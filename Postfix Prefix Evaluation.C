#include<stdio.h>
#include<string.h>
#include<math.h>

#define SIZE 20
float stack[SIZE];
int topPointer=-1;

void display() { // Displays the entire stack

	if (topPointer == -1) { // checks if stack is empty

		printf("\nThe stack is empty.");
	}
	else {

		printf("\nthe stack is ");

		for (int i = topPointer; i >= 0; i--) {
			//loop prints elements as they would be stacked
			printf("\n             %5.2f", stack[i]);
		}
	}
}

void push(float val) { // Inserts an element onto the stack

	if (topPointer != SIZE - 1) {  //Check if the stack is full

		topPointer++;
		stack[topPointer] = val;
	}
	else { //executes if the stack is full

		printf("\nOVERFLOW OCCURED!");
	}
}

float pop() { //removes an element from the stack

	if (topPointer == -1) { // checks if stack is empty

		printf("\nUNDERFLOW OCCURED!");
		return;
	}

	else { // executes if the stack has elements in it

		topPointer--;

		if (topPointer == -1)
			printf("\nThe stack is now empty.");
	}

	return stack[topPointer + 1];
}

int isOperand(char ch[1]) {

	if (ch >= '0' && ch <= '9') {

		return 1;
	}

	return 0;
}

void whatOperator(char ch[1]) {

	if (ch == '+') {

		float temp1 = pop();
		float temp2 = pop();
		push(temp1 + temp2);
	}
	else if (ch == '-') {

		float temp1 = pop();
		float temp2 = pop();
		push(temp1 - temp2);
	}
	else if (ch == '*') {

		float temp1 = pop();
		float temp2 = pop();
		push(temp1 * temp2);
	}
	else if (ch == '/') {

		float temp1 = pop();
		float temp2 = pop();
		push(temp1 / temp2);
	}
	else if (ch == '^') {

		float temp1 = pop();
		float temp2 = pop();
		push((float)pow(temp1,temp2));
	}
}

void evauatePostfix(char eq[20]) {

	for (int i = 0; i < 20; i++) {

		if (isOperand(eq[i])) {

			push(eq[i] - 48);
		}
		else if (eq[i] == ')') {

			break;
		}
		else {

			whatOperator(eq[i]);
		}
	}
}

void evauatePrefix(char eq[20]) {

	for (int i=strlen(eq)-1;i>=0; i--) {

		if (isOperand(eq[i])) {

			push(eq[i] - 48);
		}
		else {

			whatOperator(eq[i]);
		}
	}
}

int main() {

	char eq[20];
    int choice;

	printf("What type of equation is this.\n1.Postfix\n2.Prefix\n3");
	while(choice!=3){

        printf("\nEnter your choice : ");
	    scanf("%d", &choice);

	    switch (choice) {

	    case 1:
		    printf("\nEnter a valid Postfix equation (NO SPACES AND ONLY SINGLE DIGIT NUMBERS) : ");
		    scanf("%s",eq);
		    eq[strlen(eq) + 1] = ')';
		    evauatePostfix(eq);
		    display();
		    pop();
		    break;
	    case 2:
		    printf("\nEnter a valid Prefix equation (NO SPACES AND ONLY SINGLE DIGIT NUMBERS) : ");
		    scanf("%s",eq);
		    evauatePrefix(eq);
		   	display();
		   	pop();
		    break;
	    case 3:
		    printf("\nExiting...");
		    break;
	    default:
		    printf("\nINVALID INPUT!");
	    }
	}
}

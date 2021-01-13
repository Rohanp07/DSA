#include<stdio.h>

int stack[5],top=-1,i;



void pop()
{
    if (top<=-1)
        printf("\nUNDERFLOW!!\n");
    else
        printf("\nPopped elemnet is %d.\n",stack[top]);
        top--;
}
void push()
{
    int x;
    if(top>=4)
        printf("\nOVERFLOW!!\n");
    else
        {
        printf("Value to be pushed :");
        scanf("%d",&x);
        top++;
        stack[top]=x;
        }
}
void peek()
{
    if (top == -1)
        printf("UNDERFLOW!!");

    else
        printf("TOP -> %d\n",stack [top]);

}
void display()
{
     if(top>=0)
         {printf("\nSTACK ELEMENTS ARE: \n");
         for(i=top; i>=0; i--)
             printf("\n%d",stack[i]);}
     else
{
        printf("\nThe STACK is EMPTY!!");
}
}
int operations()
{
    int choice;
    printf("\nEnter your choice:");
    scanf("%d",&choice);
    switch(choice)
        {
            case 1: push();
                    return 0;
                    break;

            case 2: pop();
                    return 0;
                    break;

            case 3: peek();
                    return 0;
                    break;

            case 4: printf("Stack size: %d\n",(top+1));
                    return 0;
                    break;

            case 5: display();
                    return 0;
                    break;

            case 6: break;

            default:printf("INVALID CHOICE!!!");
                    return 0;


        }
    return 1;
}

int main()
{
    int a=0;
    while (a==0)
    {
        printf("***STACK OPERATIONS***\n");
        printf("\n1.Push\n2.Pop\n3.Peek.\n4.Size of the stack.\n5.Display. \n6.Exit.\n");
        a=operations();
    }

}

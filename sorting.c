#include <stdio.h>
#include<stdlib.h>
#include <math.h>
///swap function
int swap()
{
    int a,b,temp;
    temp=a;
    a=b;
    b=temp;
}



///Sorting function
/*int sort()
{
int i,j,k;
for (i=0;i<200;i++)
    for(j=0;j<=200-i;j++)
{

    if(a[j]>a[j+1])
    {
        swap()
    }


}



}*/


int main()
{float k;int i;float a[200]={0};
FILE*fp;
fp= fopen("Random_number.txt","r");
    for (i=0;i<200;i++)
    {

  //   k= rand();
fscanf(fp,"%f \t ",&k);
a[i]=k;
    }
    fclose(fp);
    //sorting

int j,temp;
for (i=0;i<200;i++)
    for(j=0;j<=200-i;j++)
{

    if(a[j]>a[j+1])
    {

    temp=a[j];
    a[j]=a[j+1];
    a[j+1]=temp;


    }
}
for (i=0;i<200;i++)
    printf("%d",a[i]);

}








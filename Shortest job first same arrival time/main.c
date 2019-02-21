 #include<stdio.h>
#include<stdlib.h>

int p[10],bt[10],ct[10],wt[10];
int n;

void sort()
{
    int i,j,temp1,temp2;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-(i+1);j++)
        {
            if(bt[j]>bt[j+1])
            {
                temp1=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp1;

                temp2=p[j];
                p[j]=p[j+1];
                p[j+1]=temp2;
            }}}}

int main()
{
    int i;
    printf("Enter the no. of processes\n");
    scanf("%d",&n);
    printf("Enter burst time for each process : \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
        p[i]=i+1;
    }
    sort();

    printf("Gant Chart = \n\n");
    printf(" ");
    for(i=0;i<n;i++)
    {
        printf(" P%d |",p[i]);
    }
    int c=0;
     printf("\n%d  ",c);

    for(i=0;i<n;i++)
    {
        c+=bt[i];
        printf("  %d  ",c);
        ct[i]=c;
    }
    printf("\n\n\n\n\n\n");
}

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int n;
    float num;
    printf("Enter the no.\n");
    scanf("%d",&n);
    printf("\n");
    num = round(pow(n,1.0/3.0));
    //printf("%f\n",num);
    num=num*num*num;
    //printf("%f\n",num);
    if(num == n)
        printf("\nA perfect cube !!\n\n\n");
    else
        printf("\nNot a Perfect cube :( \n\n\n");
    return 0;
}

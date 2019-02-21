#include<stdio.h>
#include<stdlib.h>

struct job{
    int at;
    int bt;
    int rem_bt;
    int ct;
    int wt;
    int process;
};

int n;
int ready_q[10],f=0,r=0;
int time=0;
struct job s[10];

void push(int prcs)
{
    ready_q[f]=prcs;
    f++;
}

void pop()
{
    f--;
}

void input()
{
    int i;
    printf("Enter the no. of processes\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        s[i].process=i+1;
        printf("Enter Arrival time for process %d ",s[i].process);
        scanf("%d",&s[i].at);
        printf("Enter the Burst time : ");
        scanf("%d",&s[i].bt);
        s[i].rem_bt=s[i].bt;
    }
}

void sort()
{
    int i,j,t;
    for(i=0;i<n-1;i+++)
        for(j=0;j<n-(i+1);j++)
        {
            if(s[j].at>s[j+1].at)
            {
                t=s[j];
                s[j]=s[j+1];
                s[j+1]=t;
            }
        }
        i=0;
        time=s[0].at;
        while(s[i].at==time)
        {
            push(s[i].process);
            i++;
        }
}

int check_sj()
{
    int i,sj;
    sj=s[r].process;
    for(i=r;i<f;i++)
    {
        if(s[i].rem_bt < sj)
            sj = s[i].process;
    }
    return sj;
}

int main()
{
    int i=0,currently_executing,process_to_execute,
    input();
    sort();
    currently_executing = ready_q[r];
    printf("GANT  CHART  : - \n");
    printf("0  ");
    while()
    {
        if(time==s[i].process)
        {
            if(currently_executing != process_to_execute)
                printf(" P%d |",s[i].process);

            time++;
            s[i].rem_bt-=1;
            i++;
            while(s[i].at==time)
            {
                push(s[i].process);
                i++;
            }

        }
        else
        {
            time++;
        }
        process_to_execute = check_sj();
    }

}

#include<stdio.h>
#include<stdlib.h>

struct schd{
    int bt;
    int process;
    int rem_bt;
    int wt;
    int tat;
};

int time_arr[20];
int ready_q[15];
int n,tq;
int time=0;
int ct[10];
int w_time;

struct schd s[10];


void input()
{
    int i;
    printf("Enter the no. of processes\n");
    scanf("%d",&n);
    printf("Enter the Burst time for each process\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&s[i].bt);
        s[i].process=i+1;
        s[i].rem_bt=s[i].bt;
        ready_q[i]=s[i].process;
        s[i].wt=0;
    }
    printf("Enter the Time Quantum\n");
    scanf("%d",&tq);
}

void rotate()
{
    int temp[4],i;
    temp[0]=s[0].rem_bt;
    temp[1]=s[0].process;
    temp[2]=ready_q[0];
    //temp[3]=bt[0];
    for(i=0;i<n-1;i++)
    {
        s[i].rem_bt=s[i+1].rem_bt;
        s[i].process=s[i+1].process;
        ready_q[i]=ready_q[i+1];
        //bt[i]=bt[i+1];
    }
    s[n-1].rem_bt=temp[0];
    s[n-1].process=temp[1];
    ready_q[n-1]=temp[2];
    //bt[n-1]=temp[3];
}

void remove_executed()
{
    int i;
    for(i=0;i<n-1;i++)
    {
        s[i].rem_bt  =  s[i+1].rem_bt;
        s[i].process =  s[i+1].process;
        ready_q[i]   =  ready_q[i+1];
        //bt[i]=bt[i+1];
    }
    n--;
}

void waiting_time(int c_executing_process)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(s[i].process==c_executing_process)
            continue;
        else
            s[s[i].process-1].wt+=w_time;
    }

}

void cal_tat(int m)
{
    int i;
    for(i=0;i<m;i++)
    {
        s[i].tat = s[i].wt + s[i].bt;
    }
    /*printf("\nBurst time\n");
    for(i=0;i<m;i++)
        printf("%d ",s[i].bt); */
}

int main()
{
    input();
    int i,m;
    int tmc=0;
    //printf("Printing the order of execution of processes\n");
    m=n;
    printf("\n\nPrinting Gant chart : \n\n");
    while(n!=0)
    {

            printf("|  P%d ",s[0].process);
            s[0].rem_bt-=tq;

            if(s[0].rem_bt<0)
            {
                w_time = tq + s[0].rem_bt;
            }
            else
                w_time=tq;

            waiting_time(s[0].process);


            if(s[0].rem_bt>0)
            {
                rotate();
                time+=tq;
                time_arr[tmc]=time;
                tmc++;
            }
            else
            {
                if(s[0].rem_bt==0)
                {
                    time+=tq;
                    time_arr[tmc]=time;
                    tmc++;
                }
                else
                {
                    time = time + (s[0].rem_bt+tq);
                    time_arr[tmc]=time;
                    tmc++;
                }
                ct[(s[0].process-1)]=time;
                remove_executed();
                //printf("\n** %d **\n",time);
            }
            /*printf("\n******Printing ready at end of first loop*******\n");
            for(i=0;i<n;i++)
                printf("%d  ",ready_q[i]); */

            /* printf("\n###Printing waiting time after loop ends###\n");
            for(i=0;i<n;i++)
                printf("%d  ",s[i].wt); */
    }
    cal_tat(m);
    printf("\n0     ");
    for(i=0;i<tmc;i++)
        printf("%d     ",time_arr[i]);

   /* printf("\n\nPrinting completion time\n");
    for(i=0;i<m;i++)
        printf("%d  ",ct[i]);
    printf("\n\nPrinting Waiting Time for each process\n");
    for(i=0;i<m;i++)
        printf("%d ",s[i].wt);
    printf("\n\nPrinting Turn around time\n");
    for(i=0;i<m;i++)
        printf("%d  ",s[i].tat); */

    printf("\n\n\n\nPROCESS  \tBURST TIME\tCOMPLETION TIME \tWAITING TIME\t TURN AROUND TIME\n");
    for(i=0;i<m;i++)
    {
        printf(" %d\t\t %d \t\t\t%d\t\t   %d \t\t    %d ",i+1,s[i].bt,ct[i],s[i].wt,s[i].tat);
        printf("\n");
    }
    return 0;
}

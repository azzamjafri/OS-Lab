#include<bits/stdc++.h>
using namespace std;
struct mem
{
	  float memory;
	  float rem;
	  int j;
	  int occ;
	  int arr[5];
	  bool occupied;
}M[5000];
struct job
{
	  int jsize;
	  int cpu;
	  int start;
	  int fin;
	  int store;
	  int state;
}J[5000],temp;
int n,m,executed=0, t=0,s=0,i,j,k,ifrag=0,waitqlength,et=-1,efrag=0,q=0,scheduled=0;
float unuse=0;
bool flag=false;
void cpus()
{
    int f=0;
    if(M[q].occupied==true)
    {
        executed++;
        t+=J[M[q].occ].cpu;
        J[M[q].occ].fin=t;
        J[M[q].occ].state=0;
        M[q].rem+=J[M[q].occ].jsize;
        M[q].occupied=false;
        f=1;
    }
    if(++q==m)
        q=0;
    if(f==0)
        cpus();
}
void jobs()
{
    while(executed<s)
    {
         // cout<<"\nAt Time : "<<t<<endl;
         for(i=0;i<n;i++)
         {
             if(J[i].state==2)
             {
                for(k=0;k<m;k++)
                {
                   if(M[k].occupied==false && M[k].rem>=J[i].jsize)
                   {
                       scheduled++;
                       J[i].state=1;
                       J[i].start=t;
                       M[k].rem-=J[i].jsize;
                       J[i].store=k;
                      // cout<<"Job "<<i+1<<" is allocated Memory Block : "<<k+1<<"\n";
                       M[k].arr[M[k].j++]=i+1;
                       M[k].occupied=true;
                       M[k].occ=i;
                       break;
                   }
                }
             }
         }
         ifrag=0;
         efrag=0;
         unuse=0;
         waitqlength=n-scheduled;
        // cout<<"\nBlock no\t%Unused\n";
        // for(k=0; k<m; ++k)
         {
             if(M[k].occupied==true)
                ifrag+=M[k].rem;
            else
            {
               // efrag+=M[k].memory;
                unuse++;
            }
           //  cout<<"M"<<k+1<<"\t\t"<<((M[k].rem/M[k].memory)*100)<<"%"<<"\n";
         }
         cout<<"\nInternal Fragmentation= "<<ifrag;

         cpus();
    }
    cout<<"\n% utilization "<<(100-(unuse/m)*100)<<"%";
   // cout<<"\nWaiting Queue Length= "<<waitqlength;


        // cout<<"\nExternal Fragmentatiob= "<<efrag<<endl;
}
int main()
{
    cout<<"Enter no. of memory blocks: ";
	cin>>m;
	cout<<"Enter sizes of all the memory blocks:\n";
	for(i=0; i<m;i++)
	{
		cout<<"Block"<<i+1<<" : ";
		cin>>M[i].memory;
		M[i].j=0;
		M[i].rem=M[i].memory;
		M[i].occupied=false;
	}
	cout<<"\nEnter no. of jobs: ";
	cin>>n;
	cout<<"Burst\tSize :-\n";
	for(i=0; i<n;i++)
	{
		cin>>J[i].cpu>>J[i].jsize;
		J[i].fin=-1;
		J[i].state=2;
	}
	for(i=0;i<n;i++)
        for(j=i;j<n;j++)
            if(J[i].cpu>J[j].cpu)
            {
                temp=J[i];
                J[i]=J[j];
                J[j]=temp;
            }
    for(i=0;i<n;i++)
    {
    	 for(k=0;k<m;k++)
    	 {
    	 	if(J[i].jsize<M[k].memory)
    	 	{
    	 		flag=true;
    	 		break;
    	 	}
    	 }
    	 if(flag==true) s++;
    	 flag=false;
    }
    cout<<endl;
    jobs();
    for(int i=0; i<n; ++i)
    {
        if(et<=J[i].fin)
            et=J[i].fin;
        //cout<<"J"<<i+1<<" : ";
       // if(J[i].fin!=-1) cout<<J[i].start<<"\n";
       // else cout<<"Not done\n";
    }
     cout<<"\nWaiting Time in Ready Queue\n";
    for(int i=0; i<n; ++i)
        cout<<"J"<<i+1<<" : "<<J[i].fin-J[i].start<<endl;
    //cout<<"\nJobs in each Partition :-\n";
  /*  for(i=0;i<m;i++)
    {
        cout<<"Memory Block "<<i+1<<" : ";
        for(k=0;k<M[i].j;k++)
            cout<<"Job"<<M[i].arr[k]<<"\t";
        cout<<endl;
    }*/
   // cout<<"\n\nTotal jobs executed: "<<n<<"\n";
    cout<<"Finish time: "<<et<<"\n";
    cout<<"Throughput: "<<(float)n/et;
    return 0;
}

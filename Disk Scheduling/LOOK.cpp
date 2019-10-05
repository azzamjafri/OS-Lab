#include<bits/stdc++.h>
using namespace std;
struct sector
{
    int arr;
    int tck;
    int sc;
    double lat;
    double fin;
    int state;
}values[20];
int n,m,head1=0,head2=0,i,j,k,dir=1;
double t=0,q,w,e=0;
   
int main()
{
     cout<<"Enter no of values to be entered: ";
    cin>>n;
    m=n;
    cout<<"Arrival\ttck\tsc\n";
    for(i=0;i<n;i++)
    {
        cin>>values[i].arr>>values[i].tck>>values[i].sc;
        values[i].state=0;
    }
    cout<<endl;
     for(i=0;i<n;i++)
    {
        int mi=200,c=-1;
        if(t<values[i].arr)
            t=values[i].arr;
        if(dir==1)
        {
            for(j=0;j<n;j++)
            {
                if(values[j].state==0 && values[j].arr<=t && abs(values[j].tck-head1)<mi && values[j].tck>head1)
                {
                    mi=abs(values[j].tck-head1);
                    c=j;
                }
            }
            if(c==-1)
            {
                dir=0;
                //head1=200;
                for(j=0;j<n;j++)
                {
                if(values[j].state==0 && values[j].arr<=t && dir==0 && abs(values[j].tck-head1)<mi)
                {
                    mi=abs(values[j].tck-head1);
                    c=j;
                }
                }
            }
        }
        else
        {
            for(j=0;j<n;j++)
            {
                if(values[j].state==0 && values[j].arr<=t && dir==0 && abs(values[j].tck-head1)<mi && values[j].tck>head1)
                {
                    mi=abs(values[j].tck-head1);
                    c=j;
                }
            }
            if(c==-1)
            {
                dir=1;
                //head1=0;
                for(j=0;j<n;j++)
                {
                if(values[j].state==0 && values[j].arr<=t && abs(values[j].tck-head1)<mi && values[j].tck>head1)
                {
                    mi=abs(values[j].tck-head1);
                    c=j;
                }
                }
            }
        }
        if(values[c].sc<head2)
            w=8-(head2-values[c].sc);
        else
            w=values[c].sc-head2;
        q=(10+0.1*abs(head1-values[c].tck)) + w;
        t+=q+1;
        values[c].lat=q;
        values[c].fin=t;
        values[c].state=1;
        e+=values[c].fin;
        head1=values[c].tck;
        head2=values[c].sc;
        cout<<"Arrival : "<<values[c].arr<<"\tFinish te : "<<values[c].fin<<'\t'<<"\tLatency : "<<values[c].lat<<endl;
    }
    cout<<endl<<"Avg. te = "<<t/(double)n<<endl<<"Avg. Latency = "<<e/(double)n<<endl;
    return 0;
}

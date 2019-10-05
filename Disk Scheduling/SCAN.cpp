#include<bits/stdc++.h>
using namespace std;
struct sector
{
    int arr;
    int tc;
    int sc;
    double lat;
    double fin;
    int st;
}values[20];
int n,m,h1=0,h2=0,i,j,k,dir=1;
double tim=0,q,w,e=0;
int main()
{
  cout<<"Enter number of values to be entered: ";
    cin>>n;
    m=n;
    cout<<"Arrival\ttc\tsc\n";
    for(i=0;i<n;i++)
    {
        cin>>values[i].arr>>values[i].tc>>values[i].sc;
        values[i].st=0;
    }
    cout<<endl;
     for(i=0;i<n;i++)
    {
        int mi=200,c=-1,b=0;
        if(tim<values[i].arr)
            tim=values[i].arr;
        if(dir==1)
        {
            for(j=0;j<n;j++)
            {
                if(values[j].st==0 && values[j].arr<=tim && abs(values[j].tc-h1)<mi && values[j].tc>h1)
                {
                    mi=abs(values[j].tc-h1);
                    c=j;
                }
            }
            if(c==-1)
            {
                dir=0;
                b=abs(h1-200);
                h1=200;
                for(j=0;j<n;j++)
                {
                if(values[j].st==0 && values[j].arr<=tim && dir==0 && abs(values[j].tc-h1)<mi)
                {
                    mi=abs(values[j].tc-h1);
                    c=j;
                }
                }
            }
        }
        else
        {
            for(j=0;j<n;j++)
            {
                if(values[j].st==0 && values[j].arr<=tim && abs(values[j].tc-h1)<mi && values[j].tc<h1)
                {
                    mi=abs(values[j].tc-h1);
                    c=j;
                }
            }
            if(c==-1)
            {
                dir=1;
                b=abs(h1-0);
                h1=0;
                for(j=0;j<n;j++)
                {
                if(values[j].st==0 && values[j].arr<=tim && abs(values[j].tc-h1)<mi && values[j].tc>h1)
                {
                    mi=abs(values[j].tc-h1);
                    c=j;
                }
                }
            }
        }
        if(values[c].sc<h2)
            w=8-(h2-values[c].sc);
        else
            w=values[c].sc-h2;
        q=(10+0.1*abs(h1-values[c].tc)+0.1*b) + w;
        tim+=q+1;
        values[c].lat=q;
        values[c].fin=tim;
        values[c].st=1;
        e+=values[c].fin;
        h1=values[c].tc;
        h2=values[c].sc;
        cout<<"Arrival : "<<values[c].arr<<"\tFinish Time : "<<values[c].fin<<'\t'<<"\tLatency : "<<values[c].lat<<endl;
    }
    cout<<endl<<"Avg. Time = "<<tim/(double)n<<endl<<"Avg. Latency = "<<e/(double)n<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
struct sector
{
    int arr;
    int tc;
    int sc;
    double fin;
    double lat;
    bool st;
}values[20];
int n,h1=100,h2=0,i,j,k;
double tim=0,q,w,e=0;
   
int main()
{
   cout<<"Enter number of values to be entered: ";
    cin>>n;
    cout<<"Arrival\ttc\tsc\n";
    for(i=0;i<n;i++)
    {
        cin>>values[i].arr>>values[i].tc>>values[i].sc;
        values[i].st=0;
    }
    cout<<endl;
   for(i=0;i<n;i++)
    {
        int mi=200;
        int c;
        if(tim<values[i].arr)
            tim=values[i].arr;
        for(j=0;j<n;j++)
        {
            if(values[j].st==0 && abs(values[j].tc-h1)<mi && values[j].arr<=tim)
            {
                mi=abs(values[j].tc-h1);
                c=j;
            }
        }
        if(values[c].sc<h2)
            w=8-(h2-values[c].sc);
        else
            w=values[c].sc-h2;
        q=(10+0.1*abs(h1-values[c].tc)) + w;
        tim+=q+1;
        values[c].lat=q;
        values[c].st=1;
        values[c].fin=tim;
        e+=values[c].lat;
        h1=values[c].tc;
        h2=values[c].sc;
        cout<<"Arrival : "<<values[c].arr<<"\tLatency : "<<values[c].lat<<"\tFinish Time "<<values[c].fin<<endl;
    }
    cout<<endl<<"Avg. Time = "<<tim/(double)n<<endl<<"Avg. Latency = "<<e/(double)n<<endl;
    return 0;
}

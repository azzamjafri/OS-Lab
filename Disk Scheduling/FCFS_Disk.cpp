#include<bits/stdc++.h>
using namespace std;
struct sector
{
    int arr;
    int tk;
    int sc;
    double lat;
    double fin;
}D[20];
int n,h1=100,h2=0,i,j,k;
double t=0,q,w,e=0;
int main()
{
   cout<<"Enter number of values to be entered: ";
    cin>>n;
    cout<<"Arrival\ttk\tsc\n";
    for(i=0;i<n;i++)
        cin>>D[i].arr>>D[i].tk>>D[i].sc;
    cout<<endl;
   for(i=0;i<n;i++)
    {
        if(t<D[i].arr)
            t=D[i].arr;
        if(D[i].sc<h2)
            w=8-(h2-D[i].sc);
        else
            w=D[i].sc-h2;
        q=(10+0.1*abs(h1-D[i].tk)) + w;
        t+=q+1;
        D[i].lat=q;
        D[i].fin=t;
        e+=D[i].lat;
        h1=D[i].tk;
        h2=D[i].sc;
        cout<<"Finish te "<<D[i].fin<<'\t'<<"Latency "<<D[i].lat<<endl;
    }
    cout<<endl<<"Avg. te = "<<t/(double)n<<endl<<"Avg. Latency = "<<e/(double)n<<endl;
    return 0;
}

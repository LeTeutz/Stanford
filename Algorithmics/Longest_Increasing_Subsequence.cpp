#include <bits/stdc++.h>
#define NMAX 100010
using namespace std;
 
ifstream f("scmax.in");
ofstream g("scmax.out");
 
int v[NMAX],d[NMAX],pred[NMAX],ans[NMAX];
int n,m,q,valpas;
 
void lcs()
{
    int j=0,pas;
    for(int i=1;i<=n;++i)
    {
        pas=valpas;
        for(j=0;pas;pas>>=1)
            if(j+pas<=m&&v[d[j+pas]]<v[i])
                j+=pas;
        if(j==m)
            ++m;
        pred[i]=d[j];
        d[j+1]=i;
    }
}
 
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>v[i];
 
    for(valpas=1;valpas<=n;valpas<<=1);
 
    lcs();
 
    g<<m<<"\n";
    for(int i=d[m];i>=1;i=pred[i])
        ans[++q]=v[i];
    for(int i=m;i>=1;--i)
        g<<ans[i]<<" ";
    return 0;
 
}

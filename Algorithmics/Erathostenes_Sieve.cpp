#include <bits/stdc++.h>
#define NMAX 2000000/2+1
using namespace std;
 
ifstream f("ciur.in");
ofstream g("ciur.out");
 
bool v[NMAX];
int k=1,n;
 
void ciur()
{
    int i,j;
    for(i=1; ((i*i)<<1)+(i<<1)<=n; ++i)
        if(v[i]==0)
        {
            for(j=(((i*i)<<1)+(i<<1)); (j<<1)+1<=n; j+=(i<<1)+1)
                v[j]=1;
        }
}
 
int main()
{
    f>>n;
    ciur();
    for(int i=1; i*2+1<=n; ++i)
        if(!v[i])
            ++k;
    g<<k<<" ";
    return 0;
}

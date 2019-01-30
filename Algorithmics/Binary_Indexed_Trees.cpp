#include<bits/stdc++.h>
#define MAX 100001
using namespace std;
 
ifstream f("aib.in");
ofstream g("aib.out");
 
int n,m,tree[MAX];
 
void update(int poz,int val)
{
    int pas=1;
    while(poz<=n)
    {
        tree[poz]+=val;
        while((poz&pas)==0)
            pas<<=1;
        poz+=pas;
        pas<<=1;
    }
}
 
int query(int poz)
{
    int pas=1,sum=0;
    while(poz>0)
    {
        sum+=tree[poz];
        while((poz&pas)==0)
            pas<<=1;
        poz-=pas;
        pas<<=1;
    }
    return sum;
}
 
int suma(int a,int b)
{
    return query(b)-query(a-1);
}
 
int cauta(int val)
{
    int j,pas;
    for(pas=1;pas<n;pas<<=1);
    for(int j=0;pas;pas>>=1)
    {
        if(j+pas<=n && tree[j+pas]<=val)
        {
            j+=pas;
            val-=tree[j];
            if(!val)
                return j;
        }
    }
    return -1;
}
 
int main()
{
    int x,a,b;
    f>>n>>m;
    for(int i=1;i<=n;++i)
    {
        f>>x;
        update(i,x);
    }
    while(m--)
    {
        f>>x;
        switch(x)
        {
            case 0: f>>a>>b; update(a,b); break;
            case 1: f>>a>>b; g<<suma(a,b)<<"\n"; break;
            case 2: f>>a; g<<cauta(a)<<"\n"; break;
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
 
FILE *f=fopen("euclid3.in","r");
ofstream g("euclid3.out");
 
int gcdExtended(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    int x0,y0,d;
    d=gcdExtended(b,a%b,x0,y0);
    x=y0;
    y=x0-(a/b)*y0;
    return d;
}
 
int main()
{
    int t,a,b,c,d,x,y;
    fscanf(f,"%d",&t);
    while(t--)
    {
        fscanf(f,"%d%d%d",&a,&b,&c);
        int d=gcdExtended(a,b,x,y);
        if(c%d!=0)
            g<<"0 0\n";
        else
            g<<x*(c/d)<<" "<<y*(c/d)<<"\n";
    }
    return 0;
}

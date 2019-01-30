#include <bits/stdc++.h>
using namespace std;
 
ifstream f("inversmodular.in");
ofstream g("inversmodular.out");
 
long long n,m,mod;
 
bool isPrime(long long x)
{
    for(int i=2;i*i<=x;++i)
        if(x%i==0)
            return 0;
    return 1;
}
 
long long getPhi(long long x)
{
    long long result=x;
    for(long long p=2;p*p<=x;++p)
    {
        //Daca p e factor prim
        if(x%p==0)
        {
            while(x%p==0)
                x/=p;
            result=(result/p)*(p-1);
        }
    }
 
    //Daca mai este un factor prim peste sqrt(x)
    if(x>1)
        result=(result/x)*(x-1);
 
    return result;
}
 
long long exp(long long a,long long e)
{
    if(e==0)
        return 1;
    if(e==1)
        return a;
    if(e%2==0)
        return exp((a*a)%mod,e/2)%mod;
    else
        return (a*exp((a*a)%mod,(e-1)/2))%mod;
}
 
int main()
{
    f>>n>>m;
    mod=m;
    if(isPrime(m))
        g<<exp(n,m-2)<<"\n";
    else
    {
        long long phi=getPhi(m);
        g<<exp(n,phi-1)<<"\n";
    }
    return 0;
}

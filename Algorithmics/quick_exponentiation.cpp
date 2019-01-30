#include <bits/stdc++.h>
using namespace std;
 
ifstream f("lgput.in");
ofstream g("lgput.out");
 
const int mod = 1999999973;
long long base, Exp;
 
long long Power(long long base, long long Exp)
{
    long long ans = 1, aux = base;
 
    for(long long i = 1; i <= Exp; i <<= 1)
    {
        if(i & Exp)
            ans = ans * aux % mod;
        aux = aux * aux % mod;
    }
 
    return ans;
}
 
int main()
{
    f >> base >> Exp;
    g << Power(base, Exp);
    return 0;
}

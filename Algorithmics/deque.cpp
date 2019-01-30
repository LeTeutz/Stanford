	
#include <bits/stdc++.h>
#define N 5000010
using namespace std;
 
ifstream f("deque.in");
ofstream g("deque.out");
 
int n,x,k,deck[N],v[N];
long long sum;
 
int main()
{
    f>>n>>k;
    for(int i=1;i<=n;++i)
        f>>v[i];
    int front=1,back=0;
    for(int i=1;i<=n;++i)
    {
        while(front<=back&&v[i]<=v[deck[back]])
            --back;
        deck[++back]=i;
        if(deck[front]==i-k)
            ++front;
        if(i-k>=0)
            sum+=v[deck[front]];
    }
    g<<sum<<"\n";
    return 0;
}

#include <bits/stdc++.h>
#define NMAX 100005
using namespace std;
 
ifstream f("dfs.in");
ofstream g("dfs.out");
 
int n,m,vizitat[NMAX],k;
vector<int> vecini[NMAX];
 
void dfs(int u)
{
    vizitat[u]=1;
    for(auto v:vecini[u])
        if(!vizitat[v])
            dfs(v);
}
 
int main()
{
    int a,b;
    f>>n>>m;
    for(int i=1;i<=m;++i)
    {
        f>>a>>b;
        vecini[a].push_back(b);
        vecini[b].push_back(a);
    }
    for(int i=1;i<=n;++i)
        if(!vizitat[i])
        {
            ++k;
            dfs(i);
        }
    g<<k;
    return 0;
}

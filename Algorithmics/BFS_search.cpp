#include <bits/stdc++.h>
#define NMAX 100001
using namespace std;
 
ifstream f("bfs.in");
ofstream g("bfs.out");
 
int n,m,s;
int vizitat[NMAX];
vector<int>vecini[NMAX];
queue<int> q;
 
void vizita()
{
    int u;
    q.push(s);
    vizitat[s]=0;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(auto v:vecini[u])
            if(vizitat[v]==-1)
            {
                vizitat[v]=vizitat[u]+1;
                q.push(v);
            }
    }
}
 
int main()
{
    int a,b;
    f>>n>>m>>s;
    for(int i=1;i<=m;++i)
    {
        f>>a>>b;
        vecini[a].push_back(b);
    }
    for(int i=1;i<=n;++i)
        vizitat[i]=-1;
    vizita();
    for(int i=1;i<=n;++i)
        g<<vizitat[i]<<" ";
    return  0;
}

#include <bits/stdc++.h>
using namespace std;
 
FILE *f = freopen("disjoint.in", "r", stdin);
FILE *g = freopen("disjoint.out", "w", stdout);
 
int n, m, father[100005], dim[100005];
 
int Dad(int x)
{
    if(x != father[x])
        x = Dad(father[x]);
    return father[x];
}
 
void Union(int x, int y)
{
    x = Dad(x);
    y = Dad(y);
 
    if(dim[x] < dim[y])
    {
        dim[y] += dim[x];
        father[x] = y;
    }
    else
    {
        dim[x] += dim[y];
        father[y] = x;
    }
}
 
int main()
{
    scanf("%d%d", &n, &m);
 
    for(int i = 1; i <= n; ++i )
    {
        father[i] = i;
        dim[i] = 1;
    }
 
    while(m--)
    {
        int type, x, y;
        scanf("%d%d%d", &type, &x, &y);
 
        if (type == 1)
            Union(x, y);
        else
            printf("%s\n", Dad(x) == Dad(y) ? "DA" : "NU");
    }
 
    return 0;
}

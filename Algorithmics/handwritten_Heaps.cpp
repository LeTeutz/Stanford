#include <bits/stdc++.h>
using namespace std;
 
ifstream f("heapuri.in");
ofstream g("heapuri.out");
 
const int MAX_SIZE=200001;
typedef int Heap[MAX_SIZE];
int n,N,cine[MAX_SIZE],unde[MAX_SIZE],k;
 
Heap H;
 
inline int father(int nod)
{
    return nod/2;
}
 
inline int left_son(int nod)
{
    return nod*2;
}
 
inline int right_son(int nod)
{
    return nod*2+1;
}
 
void min()
{
    g<<H[1]<<"\n";
}
 
void schimba(int x,int y)
{
    swap(unde[cine[x]],unde[cine[y]]);
    swap(cine[x],cine[y]);
    swap(H[x],H[y]);
}
 
void sift(int idx)
{
    if(right_son(idx)<=N&&H[right_son(idx)]<H[idx]&&H[right_son(idx)]<=H[left_son(idx)])
    {
        schimba(idx,right_son(idx));
        sift(right_son(idx));
    }
    if(left_son(idx)<=N&&H[left_son(idx)]<H[idx])
    {
        schimba(idx,left_son(idx));
        sift(left_son(idx));
    }
}
 
void percolate(int idx)
{
    if(idx>1&&H[idx]<H[father(idx)])
    {
        schimba(idx,idx/2);
        percolate(idx/2);
    }
}
 
void push(int x)
{
    H[++N]=x;
    unde[++k]=N;
    cine[N]=k;
    percolate(N);
}
 
void pop(int idx)
{
    int p=unde[idx];
    schimba(p,N);
    --N;
    sift(p);
}
 
int main()
{
    int p,x;
    f>>n;
    while(n)
    {
        f>>p;
        switch(p)
        {
        case 1:
            f>>x;
            push(x);
            break;
        case 2:
            f>>x;
            pop(x);
            break;
        case 3:
            min();
            break;
        }
        --n;
    }
    return 0;
}

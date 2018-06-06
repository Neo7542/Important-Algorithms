#include<bits/stdc++.h>
#define pi pair<int,int>
#define pb push_back
using namespace std;
vector< pair <pi ,int> > edges;
map<int ,int> dist;
int parent[100001];
bool relax(int e)
{
    bool flag = false;
    int i,x,y,w;
    for(i=1;i<=e;i++)
    {
        pair< pi ,int > p;
        p = edges[i];
        int x = p.first.first;
        int y = p.first.second;
        int w = p.second;
        if(dist[y]>dist[x]+w)
        {
            dist[y]=dist[x]+w;
            parent[y]=x;
            flag =true;
        }
    }
    return flag;
}
int main()
{
    int n,e,i,x,y,w;
    cin>>n>>e;
    for(i=1;i<=n;i++)
    {
        dist[i]=2e9;
    }
    dist[1]=0;
    for(i=1;i<=e;i++)
    {
        cin>>x>>y>>w;
        edges.pb({{x,y},w});
    }
    for(i=1;i<=n-1;i++)
    {
        relax(e);
    }
    if(relax(e))
    {
        cout<<"Negative cycle"<<endl;
    }
    else
    {
        for(i=1;i<=n;i++)
        {
            cout<<i<<" - >"<<dist[i]<<endl;
        }
    }
}

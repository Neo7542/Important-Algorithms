#include<bits/stdc++.h>
#define ll long long int
#define cap 100001
#define pi pair<int,int>
#define ff first
#define ss second
#define pb push_back
using namespace std;
vector <pi > adj[100001];
bool marked[100001];
ll prims(int s)
{
    int node,y;
    ll mincost = 0;
    priority_queue< pi , vector < pi >, greater<pi> > q;
    q.push({0,s});
    pi p;
    while(!q.empty())
    {
        p = q.top();
        q.pop();
        node = p.second;
        if(marked[node])
            continue;
        mincost+=p.first;
        marked[node] = true;
        for(int i=0;i<adj[node].size();i++)
        {
            y= adj[node][i].second;
            if(!marked[y])
            {
                q.push(adj[node][i]);
            }

        }
    }
    return mincost;
}
int main()
{
    int n,m,w,x,y,i;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>x>>y>>w;
        adj[x].pb({w,y});
        adj[y].pb({w,x});
    }
    ll mincost=prims(1);
    cout<<mincost<<endl;
}

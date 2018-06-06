#include<bits/stdc++.h>
#define ll long long int
#define cap 100001
#define pi pair<int,int>
#define ff first
#define ss second
#define pb push_back
using namespace std;
int d[100001];
bool visited[100001];
vector <pi > adj[100001];
void dijikstra(int s )
{
    int i,x,node,w;
    priority_queue< pi , vector <pi> ,greater <pi> > q;
    pi p;
    q.push({0,s});
    while(!q.empty())
    {
        p = q.top();
        q.pop();
        node = p.second;
        if(visited[node])
            continue;
        visited[node] = true;
        for(i = 0 ;i < adj[node].size();i++)
        {
            x = adj[node][i].second;
            w = adj[node][i] . first;
            if(d[node] + w < d[x])
            {
                d[x] = d[node] + w;
                q.push({d[x],x});
            }
        }
    }
}
int main()
{
     ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,i,u,v,w;
    for ( i =1; i<=100001 ; i++)
        d[i] = 10e6;
    cin>>n>>m;
    for(i = 1 ;i <= m;i++)
    {
        cin>>u>>v>>w;
        adj[u].pb({w,v});
        adj[v].pb({w,u});
    }
    d[1]=0;
    dijikstra(1);
    for(i=1;i<=n;i++)
    {
        cout<<i<<" \t"<<d[i]<<endl;
    }
}

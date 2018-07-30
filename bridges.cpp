#include<bits/stdc++.h>
#define ll long long int
#define cap 100001
#define pi pair<int,int>
#define ff first
#define ss second
#define pb push_back
using namespace std;
int low[100001] , disc[100001],parent[100001];
int Time = 0;
vector<int> adj[100001];
bool vis[100001];
void dfs(int s ,int p)
{
    parent[s] = p;
    vis[s] = true;
    disc[s]=Time++;
    low[s] = disc[s];
    for(int i = 0 ; i<adj[s].size();i++)
    {
        int v = adj[s][i];
        if(v==p) continue ; 
        if(!vis[v])
        {
            dfs(v , s);
            low[s] = min(low[v] , low[s]);
            if(low[v] > disc[s])
            {
                cout<<s<<" "<<v<<endl;
            }
        }
        else
            low[s] =min(low[s] , disc[v] );
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,x,y,i;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    
    dfs(1,-1);
    
    for(i=1;i<=n;i++)
        cout<<i<<" "<<disc[i]<<" " <<low[i]<<endl;
}


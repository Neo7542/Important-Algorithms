#include<bits/stdc++.h>
#define ll long long int
#define cap 100001
#define pi pair<int,int>
#define ff first
#define ss second
#define pb push_back
using namespace std;
int Time = 0;
int low[100001] , parent[100001] , disc[100001];
vector<int> adj[100001];
bool vis[100001];
vector<int> arti;
void dfs(int s , int p)
{
    int i,v;
    parent[s] = p;
    disc[s]=Time++;
    low[s] = disc[s];
    vis[s] = true;
    int child = 0;
    for(i=0;i<adj[s].size();i++)
    {
        v = adj[s][i];
        if(v== p)
        {
            continue;
        }
        else
        {
            
            if(!vis[v])
            {
                child++;
                dfs(v , s);
                low[s] = min(low[s] , low[v]);
                if(disc[s] <= low[v] && parent[s]!=-1)
                {
                    arti.pb(s);
                }
                if(parent[s]==-1 && child>1)
                {
                    arti.pb(s);
                }
            }
            else
                low[s] = min(low[s] , disc[v]);
        }
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
    dfs(1 , -1);
    for(i=1;i<=n;i++)
    {
        cout<<i<<" - > " <<disc[i]<<" "<<low[i]<<endl;
    }
    for(int i = 0;i<arti.size();i++)
    {
        cout<<arti[i]<<endl;
    }
}


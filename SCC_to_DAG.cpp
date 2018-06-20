#include<bits/stdc++.h>
#define ll long long int
#define cap 100001
#define pi pair<int,int>
#define ff first
#define ss second
#define pb push_back
using namespace std;
vector<int> adj[100001];
vector<int> rev[100001];
vector<int> conn[100001];
vector<int> temp;
vector< pi> edges;
int C[100001];
bool vis[100001],visd[100001];
map< pi , bool > evis;
stack<int > S ;
void dfs(int s)
{
    vis[s]=true;
    for(int i=0;i<adj[s].size();i++)
    {
        if(!vis[adj[s][i]])
            dfs(adj[s][i]);
    }
    S.push(s);
}
void Connected(int s)
{
    vis[s]=true;
    temp.pb(s);
    for(int i=0;i<rev[s].size();i++)
    {
        if(!vis[rev[s][i]])
            Connected(rev[s][i]);
    }
}
void constructDAG()
{
    pi p;
    for(int i=0;i<edges.size();i++)
    {
        p = edges[i];
        if(! evis[{p.first , p.second}])
        {
            conn[C[p.first]].pb(C[p.second]);
            evis[{p.first , p.second}] = true;
        }
    }
}
void dfsDAG(int s)
{
    visd[s]=true;
    for(int i=0;i<conn[s].size();i++)
    {
        if(!visd[conn[s][i]])
            dfsDAG(conn[s][i]);
    }
    cout<<s<<" ";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,i,x,y,s,c=0;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>x>>y;
        edges.pb({x,y});
        evis[{x,y}] = false;
        adj[x].pb(y);
        rev[y].pb(x);
    }
    for(i=1;i<=n;i++)
    {
        if(!vis[i])
            dfs(i);
    }
    c=1;
    memset(vis , false , sizeof vis);
    while(!S.empty())
    {
        
        s=S.top();
        S.pop();
        if(!vis[s])
        {
            Connected(s);
            for(i=0;i<temp.size();i++)
            {
                C[temp[i]] = c;
                cout<<temp[i]<<" "<<c<<" ";
            }
            cout<<endl;
            temp.clear();
            c++;
        }
        
    }
    constructDAG();
    for(i=1;i<c;i++)
    {
        if(!visd[i])
        {
            dfsDAG(i);
            cout<<endl;
        }
    }
}


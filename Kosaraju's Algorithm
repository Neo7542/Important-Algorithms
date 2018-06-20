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
bool vis[100001];
stack<int > S ;
int cnt;
void dfs(int s)
{
    int i;
    vis[s]=true;
    for(i=0;i<adj[s].size();i++)
    {
        if(!vis[adj[s][i]])
            dfs(adj[s][i]);
    }
    S.push(s);
}
void Connected(int s)
{
    int i;
    vis[s]=true;
    cout<<s<<" ";
    for(i=0;i<rev[s].size();i++)
    {
        if(!vis[rev[s][i]])
        {
            Connected(rev[s][i]);
        }
    }
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
        adj[x].pb(y);
        rev[y].pb(x);
    }
    for(i=1;i<=n;i++)
    {
        if(!vis[i])
            dfs(i);
    }
    memset(vis,false,sizeof vis);
    cout<<"Connected Components are :\n";
    while(!S.empty())
    {
        s=S.top();
        S.pop();
        cnt=0;
        if(!vis[s])
        {
            Connected(s);
            c++;
            cout<<endl;
        }
    }
   cout<<"Connected Components Count :  "<<c<<"\n";
}


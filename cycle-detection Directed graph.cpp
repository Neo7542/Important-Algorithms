/*__saty__*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ff first
#define ss second
#define mod 1000000007
#define N 100100
#define pb push_back
#define inf LLONG_MAX
#define neginf -1e18
#define pi pair<ll,ll>
int black[N],graycol[N],ans;
vector<int> adj[N];
stack<int> white;
void dfs(int node)
{
    int i,p;
    for(i=0;i<adj[node].size();i++)
    {
        p=adj[node][i];
        if(black[p]==1)
        continue;
        if(graycol[p]==1)
        {
            ans=1;
            continue;
        }
        graycol[p]=1;
        dfs(p);
    }
    graycol[node]=0;
    black[node]=1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,a,b,i,p;
    cin>>n;
    cin>>m;
    for(i=0;i<m;i++)
    {
        cin>>a>>b;
        adj[a].pb(b);
    }
    for(i=1;i<=n;i++)
    white.push(i);
    while(!white.empty())
    {
        p=white.top();
        graycol[p]=1;
        dfs(p);
        graycol[p]=0;
        black[p]=1;
        white.pop();
    }
    cout<<ans;
    return 0;
}

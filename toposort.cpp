#include<bits/stdc++.h>
#define ll long long int
#define cap 100001
#define pi pair<int,int>
#define ff first
#define ss second
#define pb push_back
using namespace std;
int indegree[100001];
bool vis[100001];
vector<int > adj[100001];
vector<int> t;
int n;
void toposort()
{
    int s,x;
    priority_queue<int , vector<int> , greater <int> > q;
    for(int i=1;i<=n;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }

    memset(vis,false,sizeof vis);
   //
    //priority_queue<int , vector<int> , greater <int> > pq;
    while(!q.empty())
    {
        x = q.top();
        //cout<<x<<endl;
        q.pop();
        t.pb(x);
        vis[x]=true;
        for(int i=0;i<adj[x].size();i++)
        {
            if(!vis[adj[x][i]])
            {
                indegree[adj[x][i]]--;
                if(indegree[adj[x][i]] == 0)
                {
                   // cout<<adj[x][i]<<endl;
                   // pq.push(adj[x][i]);
                  q.push(adj[x][i]);
                }
            }
        }
        /*while(!pq.empty())
        {
            //cout<<pq.top()<<endl;
           // t.pb(pq.top());
            q.push(pq.top());
            pq.pop();
        }*/
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m,x,y,i;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        indegree[i]=0;
    }
    for(i=0;i<m;i++)
    {
        cin>>x>>y;
        adj[x].pb(y);
        indegree[y]++;
    }
    toposort();
    vector<int>::iterator it;
    for(it=t.begin();it!=t.end();it++)
       cout<<*it<<" ";
}


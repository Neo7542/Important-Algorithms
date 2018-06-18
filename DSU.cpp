#include<bits/stdc++.h>
#define ll long long int
#define cap 100001
#define pi pair<int,int>
#define ff first
#define ss second
#define pb push_back
using namespace std;
int arr[100001];
int size[100001];
int root(int i)
{
    while(i!=arr[i])
    {
        i=arr[i];
    }
    return i;
}
int Union(int x , int y)
{
    int root_x = root(x);
    int root_y = root(y);
    if(root_x!=root_y)
    {
        if(size[root_x]>size[root_y])
        {
            arr[root_y] = arr[root_x];
            size[root_x]+=size[root_y];
        }
        else
        {
            arr[root_x] = arr[root_y];
            size[root_y]+=size[root_x];
        }
    }
}
int find(int x,int y)
{
    if(root(x)==root(y))
        return 1;
    else
        return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,e,q,x,y,i;
    cin>>n>>e;
    for(i=1;i<=n;i++)
       {
           size[i]=1;
           arr[i]=i;
       }
    for(i=1;i<=e;i++)
    {
        cin>>x>>y;
        Union(x , y);
    }
    cin>>q;
    for(i=1;i<=q;i++)
    {
        cin>>x>>y;
        if(find(x,y))
            cout<<"connected\n";
        else
            cout<<"Not connected\n";
    }
}


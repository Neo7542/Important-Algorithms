#include<bits/stdc++.h>
#define ll long long int
#define cap 100001
#define pi pair<int,int>
#define ff first
#define ss second
#define pb push_back
using namespace std;
ll findExpo(ll x , ll n)
{
   if(n==0)
        return 1; 
   if(n%2==0)
   {
       return findExpo((x*x , n/2);
   }
   else
   {
       return x * findExpo(x , n-1);
   }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll x, n;
    cin>>x>>n; // calculate x^n . 
    ll val = findExpo(x , n);
    cout<<val<<endl;
}

//Time complexity: O(log N)
//Memory complexity: O(1)

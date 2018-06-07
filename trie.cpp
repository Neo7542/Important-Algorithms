#include<bits/stdc++.h>
#define ll long long int
#define cap 100001
#define pi pair<int,int>
#define ff first
#define ss second
#define pb push_back
using namespace std;
struct Node{
  map <char , Node *> m;
  int now;
};
void insert(string s , Node *root)
{
    Node *temp = root;
    for(int i=0;i<s.length();i++)
    {
        if(temp->m[s[i]]==NULL)
        {
            Node *nn = new Node();
            temp->m[s[i]] = nn;
            nn->now = 0;
            temp = nn;
        }
        else
        {
            temp = temp->m[s[i]];
        }
    }
    temp->now++;
}
void display(string x , Node *root)
{
    if(root->now >= 1){
       for(int i=1;i<=root->now;i++)
       {
           cout<<x<<endl;
       }
    }
    map <char , Node * > ::iterator it;
    it = root->m.begin();
    while(it!=root->m.end())
    {
        x = x + it->first;
        display(x ,it->second);
        x = x.substr(0,x.length()-1);
        it++;
    }
}
bool search(string s , Node *root)
{
    Node *temp = root;
    for(int i=0;i<s.length();i++)
    {
        if(temp->m[s[i]]==NULL)
        {
            return false;
        }
        temp = temp->m[s[i]];
    }
    display(s,temp);
    return true;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,i;
    string s;
    cin>>n;
    Node *root = new Node();
    for(i=1;i<=n;i++)
    {
        cin>>s;
        insert(s , root);
    }

    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>s;
        if(!search(s ,root))
        {
            cout<<"Not Found"<<endl;
        }
    }

}


#include<bits/stdc++.h>
#define ll long long int
#define cap 100001
#define pi pair<int,int>
#define ff first
#define ss second
#define pb push_back
using namespace std;
struct Node{
    map <char , Node * > m;
    bool eow;
};
void insert(string s , Node *root)
{
    Node *temp=root;
    for(int i=0;i<s.length();i++)
    {
        if(temp->m[s[i]]==NULL)
        {
            Node *nn = new Node;
            temp->m[s[i]] = nn;
            nn->eow = false;
            temp = nn;
        }
        else
        {
            temp = temp->m[s[i]];
        }
    }
    temp->eow = true;

}
bool search(string s , Node *root)
{
    Node* temp = root;
    for(int i=0;i<s.length();i++)
    {
        if(temp->m[s[i]]==NULL)
            return false;
        else
            temp = temp->m[s[i]];
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n ,i;
    string s;
    cin>>n;
    Node *root = new Node();
    root->eow = false;
    for(i=1;i<=n;i++)
    {
        cin>>s;
        insert(s , root);
    }
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>s;
        cout<<search(s,root)<<endl;
    }
}



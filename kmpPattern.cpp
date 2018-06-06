#include<bits/stdc++.h>
#define ll long long int
#define cap 100001
#define pi pair<int,int>
#define ff first
#define ss second
#define pb push_back
using namespace std;
int lps[100001];
void computeLps(string patt)
{
    int j=0,i=1;
    lps[0]=0;
    while(i<patt.length())
    {
        if(patt[i]==patt[j])
        {
            lps[i]=j+1;
            i++;
            j++;
        }
        else
        {
            if (j != 0)
            {
                j = lps[j-1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

}
void kmpSearch(string s , string patt)
{
    computeLps(patt);
    for(int i=0;i<patt.length();i++)
        cout<<lps[i]<<" ";
    cout<<endl;
    int j=0;
    for(int i=0;i<s.length();)
    {
        if(s[i]==patt[j])
        {
            if(j==(patt.length()-1))
            {
                cout<<"String found\n"<<endl;
                return ;
            }
          i++;
          j++;
        }
        else
        {
            if(j!=0)
            j=lps[j-1];
            else
                i++;
        }
    }
    cout<<"String not found"<<endl;
}
int main()
{
    string s,patt;
    cin>>s;
    cin>>patt;
    kmpSearch(s,patt);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[100001];
int partition(int start , int last)
{
    int pivot = a[last];
    int pInd = start;
    for(int i=start;i<=last- 1;i++)
    {
        if(a[i]<pivot)
        {
            swap(a[i],a[pInd]);
            pInd++;
        }
    }
    swap(a[last] , a[pInd]);
    return pInd;
}
void quickSort(int start ,  int last)
{
    if(start>=last)
        return;
    int pInd = partition(start , last);
    quickSort(start , pInd - 1);
    quickSort(pInd+1 , last) ;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    quickSort(0 , n-1);
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}

#include<bits/stdc++.h>
using namespace std;
int a[101];
void max_heapify(int i , int n)
{
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;
    if(left<=n && a[left]>a[i])
        largest = left;
    if(right<=n && a[right]>a[largest])
    {
        largest = right;
    }
    if(largest!=i)
    {
        swap(a[i],a[largest]);
        max_heapify(largest , n );
    }
}
void heapsort(int n)
{
    int i;
    int length=n;
    for(i=1;i<=n-1;i++)
    {

        swap(a[1] , a[length]);
        length--;
        max_heapify(1 , length);
    }

}
void insertEle(int x , int n)
{
    a[n]= x;
    int i = n;
    while(i>1 && a[i/2]<a[i])
    {

        swap(a[i],a[i/2]);
        i=i/2;

    }
}
int main()
{
    int n ,i ;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(i=n/2;i>=1;i--)
    {
        max_heapify(i , n);
    }

    int x , y;
    cin>>x;
    for(i=1;i<=x;i++)
    {
        cin>>y;
        n++;
        insertEle(y,n);
    }
    heapsort(n);
    for(i=1;i<=n;i++)
    {
        cout<<a[i]<<" "<<endl;
    }
}

#include<bits/stdc++.h>
using namespace std;

int main()
{
    set<int, greater<int> > s;
    int n;
    cout<<"Enter no. of elements: ";
    cin>>n;
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        s.insert(x);
    }
    set<int, greater<int> >::iterator it;
    int c=0;
    cout<<"Top 10 elements : ";
    for(it=s.begin();it!=s.end() && c<10;it++)
    {
        cout<<*it<<" ";
        c++;
    }
    return 0;
}

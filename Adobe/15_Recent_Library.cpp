/*
Most Recent Library
Given two library versions of an executable: for example, "10.1.1.3" and "10.1.1.9" or "10" and "10.1". Find out which one is more recent? Strings can be empty also.

Sample Input
2
10.1.1.3
10.1.1.9
Sample Output
10.1.1.9

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;
    cout<<"Enter First Library : ";
    cin>>a;
    
    cout<<"Enter Second Library : ";
    cin>>b;

    int n = a.length(), m = b.length();
    int i=0, j=0;
    bool flag = true;

    while(i<n && j<m)
    {
        if(b[j] > a[i])
        {
            flag = false;
            break;
        }
        if(a[i] > b[j])
            break;
        i++;
        j++;
    }
    
    if(i == n && j<m)
        flag = false;
    
    if(flag)
        cout<<"First Library : "<<a<<" is recent"<<endl;

    else
        cout<<"Second Library : "<<b<<" is recent"<<endl;
    
    return 0;
}

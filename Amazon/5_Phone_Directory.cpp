#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<string> fun(string s,string con[],int n)
    {
        int l = s.length();
        vector<string> v;
        map<string, int> m;
        for(int i=0;i<n;i++)
        {
            if(con[i].length()>=l && s == con[i].substr(0,l))
                m[con[i]]++;
        }
        for(auto i : m)
            v.push_back(i.first);
        if(v.size()==0) 
            v.push_back("0");
        return v;
    }
    
    vector<vector<string> > displayContacts(int n, string con[], string s)
    {
        vector<vector<string> > ans;
        for(int k=1;k<=s.length();k++)
        {
            vector<string> v = fun(s.substr(0,k),con,n);
            ans.push_back(v);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends

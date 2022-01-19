
Prerequisite : Longest Increasing Subsequence (https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1)
Prerequisite : Longest Common Subsequence (https://leetcode.com/problems/longest-common-subsequence/)

class Solution {
  public:
  
    int longestSubsequence(vector<int> a) 
    {
        int n = a.size();
        vector<int> res;
        
        for(int i=0; i<n; i++)
        {
            auto it = lower_bound(res.begin(), res.end(), a[i]);
            
            if(it == res.end())
                res.push_back(a[i]);
            
            else
                *it = a[i];
                
        }
        
        return res.size();   
    }
    
    int minInsAndDel(int a[], int b[], int n, int m) 
    {
        unordered_map<int, int> mp;
        for(int i=0; i<m; i++)
            mp[b[i]]++;
        
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            if(mp.find(a[i]) != mp.end())
                v.push_back(a[i]);
        }
            
        int l = longestSubsequence(v);
        
        return (n - l) + (m - l);
    }
};

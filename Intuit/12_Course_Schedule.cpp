class Solution {
public:
    bool isCycle(vector<int> adj[], int i, vector<bool> &vis, vector<bool> temp,vector<int> &ans)
    {
        vis[i] = true;
        temp[i] = true;
        for(auto x : adj[i])
        {
            if(temp[x])
                return true;
            if(!vis[x] && isCycle(adj,x,vis,temp,ans))
                return true;
        }
        ans.push_back(i);
        return false;
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& v) 
    {
        vector<int> adj[n];
        vector<int> ans;
        int m = v.size();
        for(int i=0;i<m;i++)
            adj[v[i][0]].push_back(v[i][1]);
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                vector<bool> temp(n,false);
                if(isCycle(adj,i,vis,temp,ans))
                {
                    ans.clear();
                    return ans;
                }
            }
        }
        return ans;
    }
};

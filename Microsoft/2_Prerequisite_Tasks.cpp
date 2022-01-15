class Solution {
public:
    bool isCycle(vector<int> adj[], int ind, vector<bool> &vis, vector<bool> X)
    {
        vis[ind] = true;
        X[ind] = true;
        for(auto i : adj[ind])
        {
            if(X[i])
                return true;
            if(!vis[i] && isCycle(adj,i,vis,X))
                return true;
        }
        return false;
    }
	bool isPossible(int n, vector<pair<int, int> >& p) 
	{
	    vector<int> adj[n];
	    for(int i=0;i<p.size();i++)
	    {
	        adj[p[i].first].push_back(p[i].second);
	    }
	    vector<bool> vis(n,false);
	    for(int i=0;i<n;i++)
	    {
	        vector<bool> X(n,false);
	        if(isCycle(adj,i,vis,X))
	            return false;
	    }
	    return true;
	}
};

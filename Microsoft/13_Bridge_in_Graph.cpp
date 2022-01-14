class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        for(auto i=adj[c].begin();i!=adj[c].end();i++)
        {
            if(*i == d)
            {
                adj[c].erase(i);
                break;
            }
        }
        for(auto i=adj[d].begin();i!=adj[d].end();i++)
        {
            if(*i == c)
            {
                adj[d].erase(i);
                break;
            }
        }
        vector<bool> vis(V,false);
        queue<int> q;
        q.push(c);
        vis[c] = true;
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            for(auto i : adj[x])
            {
                if(!vis[i])
                {
                    vis[i] = true;
                    q.push(i);
                }
            }
        }
        
        return !vis[d];
    }
};

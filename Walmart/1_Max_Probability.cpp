
class Solution {
public:
    void fun(vector<pair<int, double> > adj[], int start, vector<bool> &vis, vector<double> &dis, priority_queue<pair<double, int> > &pq)
    {
        if(start == -1)
            return;
        vis[start] = true;
        for(auto i : adj[start])
        {
            if(dis[start] * i.second > dis[i.first])
            {
                dis[i.first] = dis[start] * i.second;
                pq.push({dis[start] * i.second, i.first});
            }
        }
        int ind = -1;
        if(!pq.empty())
        {
            ind = pq.top().second;
            pq.pop();
        }
        fun(adj, ind, vis, dis, pq);
    }
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& s, int start, int end) 
    {
        vector<pair<int, double> > adj[n];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], s[i]});
            adj[edges[i][1]].push_back({edges[i][0], s[i]});
        }
        vector<bool> vis(n, false);
        vector<double> dis(n, DBL_MIN);
        dis[start] = 1;
        priority_queue<pair<double, int> > pq;
        fun(adj, start, vis, dis, pq);
        return (dis[end] == DBL_MIN) ? 0 : dis[end];
    }
};



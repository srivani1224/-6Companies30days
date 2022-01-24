class Solution {
public:
    
    int findCircleNum(vector<vector<int>>& v) 
    {
        int n =  v.size();
        vector<bool> vis(n,false);
        int ans = 0;
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                ans++;
                q.push(i);
                while(!q.empty())
                {
                    int l = q.size();
                    for(int i=0;i<l;i++)
                    {
                        int x = q.front();
                        q.pop();
                        vis[x] = true;
                        for(int j=0;j<n;j++)
                        {
                            if(v[x][j] && !vis[j])
                                q.push(j);
                        }
                    }
                }
            }
        }
        return ans;
    }
};

class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int l[8] = { -1, -1, -1, 0, 0, 1, 1, 1};
    int r[8] = { -1, 0, 1, -1, 1, -1, 0, 1};
    
    bool isValid(int X, int Y, int n, int m)
    {
        return (X>=0 && X<n && Y>=0 && Y<m);
    }
    
    int findMaxArea(vector<vector<int>>& v) {
        int n = v.size(), m = v[0].size();
        int ans=0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && v[i][j] == 1)
                {
                    queue<pair<int,int> > q;
                    q.push({i,j});
                    vis[i][j] = true;
                    int c = 1;
                    while(!q.empty())
                    {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        for(int k=0; k<8; k++)
                        {
                            int X = x + l[k];
                            int Y = y + r[k];
                            if(isValid(X,Y,n,m) && !vis[X][Y] && v[X][Y] == 1)
                            {
                                q.push({X,Y});
                                c++;
                                vis[X][Y] = true;
                            }
                        }
                    }
                    ans = max(ans, c);
                }
                vis[i][j] = true;
            }
        }
        return ans;
    }
};

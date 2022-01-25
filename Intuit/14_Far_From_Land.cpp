class Solution {
public:
    int l[4] = {-1, 0, 0, 1};
    int r[4] = {0, 1, -1, 0};
    
    int maxDistance(vector<vector<int>>& v) 
    {
        int n = v.size();
        vector<vector<int>> vis(n,vector<int>(n,-1));
        queue<pair<int,int> > q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i][j]==1)
                {
                    q.push({i,j});
                    vis[i][j] = 0;
                }
            }
        }
        int c = 1, ans = -1;
        while(!q.empty())
        {
            int len =  q.size();
            for(int i=0;i<len;i++)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int k=0;k<4;k++)
                {
                    int X = x+l[k];
                    int Y = y+r[k];
                    if((X>=0 && Y>=0 && X<n && Y<n) && (vis[X][Y] == -1))
                    {
                        vis[X][Y]  =  c;
                        ans = max(ans, c);
                        q.push({X,Y});
                    }
                }
            }
            c++;
        }
        return ans;
    }
};

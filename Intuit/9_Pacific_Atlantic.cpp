class Solution {
public:
    int l[4] = {-1, 1, 0, 0};
    int r[4] = {0, 0, -1, 1};
    bool isValid(int i, int j, int n, int m)
    {
        if(i>=0 && j>=0 && j<m && i<n)
            return true;
        return false;
    }
    void dfs(vector<vector<int>>& v, int n, int m, int i, int j, vector<vector<bool>> &vis)
    {
        vis[i][j] = true;
        for(int k=0;k<4;k++)
        {
            int X = i+l[k];
            int Y = j+r[k];
            if(isValid(X,Y,n,m) && !vis[X][Y] && v[X][Y] >= v[i][j])
            {
                vis[X][Y] = true;
                dfs(v,n,m,X,Y,vis);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& v) 
    {
        int n = v.size();
        int m = v[0].size();
        vector<vector<int>> ans;
        vector<vector<bool>> pacific(n,vector<bool>(m, false));
        vector<vector<bool>> atlantic(n,vector<bool>(m, false));
        
        for(int i=0;i<n;i++)
        {
            dfs(v,n,m,i,0,pacific);
            dfs(v,n,m,i,m-1,atlantic);
        }
        for(int i=0;i<m;i++)
        {
            dfs(v,n,m,0,i,pacific);
            dfs(v,n,m,n-1,i,atlantic);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};

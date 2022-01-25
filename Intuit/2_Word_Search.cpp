class Solution {
public:
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};
    bool isValid(int i, int j, int n, int m)
    {
        return (i>=0 && j>=0 && i<n && j<m);
    }
    bool dfs(vector<vector<char>>& v, string s, vector<vector<bool> > &vis, int i, int j, int ind)
    {
        if(ind == s.length())
            return true;
        vis[i][j] = true;
        for(int k=0; k<4; k++)
        {
            int X = i+x[k];
            int Y = j+y[k];
            if(isValid(X,Y,v.size(),v[0].size()) && !vis[X][Y] && s[ind] == v[X][Y] && dfs(v,s,vis,X,Y,ind+1))
                return true;
        }
        vis[i][j] = false;
        return false;
    }
    bool isWordExist(vector<vector<char>>& v, string s) 
    {
        int l = s.length();
        int n =  v.size(), m = v[0].size();
        vector<vector<bool> > vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j] == s[0] && dfs(v,s,vis,i,j,1))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

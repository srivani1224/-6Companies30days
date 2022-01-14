class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > v, int r, int c) 
    {
        vector<int> ans;
        int R = 0, C = 0, n = r, m = c;
        while( R < n && C < m )
        {
            for(int j = C; j < m; j++)
            {
                ans.push_back(v[R][j]);
            }
            R++;
            
            for(int i = R; i < n; i++)
            {
                ans.push_back(v[i][m-1]);
            }
            m--;
            
            if(n > R)
            {
                for(int j = m-1; j >= C; j--)
                {
                    ans.push_back(v[n-1][j]);
                }
            }
            n--;
            
            if(m  > C)
            {
                for(int i = n-1; i >= R; i--)
                {
                    ans.push_back(v[i][C]);
                }
            }
            C++; 
        }
        return ans;
    }
};

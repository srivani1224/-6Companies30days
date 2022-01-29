class Solution {
public:
    int fun(int l, int r, vector<vector<int> > &dp)
    {
        if(l>=r)
            return dp[l][r] = 0;
        if(dp[l][r] != INT_MAX)
            return dp[l][r];
        for(int i=l;i<=r;i++)
        {
            dp[l][r] = min(dp[l][r] , max(i + fun(l,i-1,dp), i + fun(i+1,r,dp)));
        }
        return dp[l][r];
    }
    
    int getMoneyAmount(int n) 
    {
        vector<vector<int> > dp(500, vector<int>(500, INT_MAX));
        return fun(1,n,dp);
    }
};

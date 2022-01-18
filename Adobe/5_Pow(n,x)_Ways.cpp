class Solution{
    public:
    
    long long numOfWays(int n, int x)
    {
        long long dp[n+1];
        memset(dp, 0, sizeof(dp));
        
        dp[0] = dp[1] = 1;
        
        long long int ma = pow(n, 1.0/x);
        
        for(int i = 2; i<=ma; i++)
        {
            long long int curr = pow(i,x);
            
            for(int j = n; j>=curr; j--)
                dp[j] += dp[j-curr];
        }
    
        return dp[n];
    }
};

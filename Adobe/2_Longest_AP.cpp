class Solution{   
public:
    int lengthOfLongestAP(int a[], int n) 
    {
        if(n<=2)
            return n;
        int dp[n][n], ans = 2;
        for(int i=0;i<n;i++)
            dp[i][n-1] = 2;
        for(int j = n-2; j>0; j--)
        {
            int i = j-1, k = j+1;
            while(i>=0 && k<=n-1)
            {
                if(a[i]+a[k] == (2 * a[j]))
                {
                    dp[i][j] = 1 + dp[j][k];
                    ans = max(ans, dp[i][j]);
                    i--;
                    k++;
                }
                else if(a[i]+a[k] > (2 * a[j]))
                {
                    dp[i][j] = 2;
                    i--;
                }
                else
                    k++;
            }
            while(i>=0)
            {
                dp[i][j] = 2;
                i--;
            }
        }
        return ans;
    }
};

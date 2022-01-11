class Solution{

  public:
	int minDifference(int a[], int n)  
	{ 
	    int s=0;
	    for(int i=0;i<n;i++)
	        s+=a[i];
	    bool dp[n+1][s+1];
	    for(int i=0;i<=n;i++)
	    {
	        for(int j=0;j<=s;j++)
	        {
	            if(i==0)
	                dp[i][j] = false;
	            if(j==0)
	                dp[i][j] = true;
	            else if(i!=0 && j!=0)
	            {
	                if(j>=a[i-1])
	                {
	                    dp[i][j] = (dp[i-1][j] || dp[i-1][j-a[i-1]]);
	                }
	                else
	                {
	                    dp[i][j] = dp[i-1][j];
	                }
	            }
	        }
	    }
	    int ans =  s;
	    for(int i=0;i<=s/2;i++)
	    {
	        if(dp[n][i])
	            ans = min(ans, abs(s-(2*i)));
	    }
	    return ans;
	} 
};

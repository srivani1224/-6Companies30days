class Solution {
public:

    int dp[1000][1000];
    int fun(vector<int> &v, int l, int r)
    {
        if(l == r)
            return dp[l][r] = v[l];
        if(l+1 == r)
            return dp[l][r] = max(v[l], v[r]);
        if(l > r)
            return dp[l][r] = 0;
        if(dp[l][r]!=-1)
            return dp[l][r];
        int x = v[l] + min( fun(v,l+2,r), fun(v,l+1,r-1) );
        int y = v[r] + min( fun(v,l,r-2), fun(v,l+1,r-1) );
        return dp[l][r] = max(x,y);
    }

    int maxCoins(vector<int> &v, int n)
    {
        memset(dp, -1, sizeof(dp));
	    return fun(v, 0, n-1);
    }
};

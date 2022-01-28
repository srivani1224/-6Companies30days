class Solution {
public:
    int dp[501][501];
    int fun(vector<int>& v, int l, int r)
    {
        if(l > r)
            return dp[l][r] = 0;
        if(l == r)
            return dp[l][r] = v[l];
        if(l+1 == r)
            return dp[l][r] = max(v[l], v[r]);
        if(dp[l][r] != -1)
            return dp[l][r];
        int x = v[l] + min( fun(v, l+2, r), fun(v, l+1, r-1));
        int y = v[r] + min( fun(v, l+1, r-1), fun(v, l, r-2));
        return dp[l][r] = max(x, y);
    }
    bool stoneGame(vector<int>& v) 
    {
        memset(dp, -1, sizeof(dp));
        int n = v.size();
        int s = 0;
        for(int i=0;i<n;i++)
            s += v[i];
        int X = fun(v, 0, n-1);
        return (X > s - X)? true : false;
    }
};

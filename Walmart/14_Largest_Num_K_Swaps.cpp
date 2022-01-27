class Solution
{
    public:
    void fun(string s, int i, int n, int k, string &ans)
    {
        if(i == n || k == 0)
            return;
        char ma = s[i];
        for(int j = i+1; j<n; j++)
            ma = max(ma, s[j]);
        if(ma != s[i])
            k--;
        for(int j = i; j<n; j++)
        {
            if(s[j] == ma)
            {
                swap(s[i], s[j]);
                ans = max(ans, s);
                fun(s, i+1, n, k, ans);
                swap(s[i], s[j]);
            }
        }
    }
    
    string findMaximumNum(string s, int k)
    {
       int n = s.length();
       string ans = s;
       fun(s, 0, n, k, ans);
       return ans;
    }
};

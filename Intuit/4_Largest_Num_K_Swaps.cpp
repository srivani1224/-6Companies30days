class Solution
{
    public:
    void findMax(string s, int i, int n, int k, string &ans)
    {
        if(i==n || k<=0)
            return ;
        char ma = s[i];
        for(int j = i+1;j<n;j++)
        {
            ma = max(ma, s[j]);
        }
        if(ma != s[i])
            k--;
        for(int j=n-1; j>=i; j--)
        {
            if(s[j] == ma)
            {
                swap(s[i], s[j]);
                ans = max(ans, s);
                findMax(s,i+1,n,k,ans);
                swap(s[i],s[j]);
            }
        }
    }
    
    string findMaximumNum(string s, int k)
    {
        int n = s.length();
        string ans = s;
        findMax(s,0,n,k,ans);
        return ans;
    }
};

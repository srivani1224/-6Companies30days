class Solution{
    public:
    string amendSentence (string s)
    {
        int n = s.length();
        string ans = "";
        if(s[0]<='Z' && s[0]>='A')
            ans += (s[0] + 32);
        else
            ans += s[0];
        for(int i=1;i<n;i++)
        {
            if(s[i]<='Z' && s[i]>='A')
            {
                ans += ' ';
                ans += (s[i] + 32);
            }
            else
                ans += s[i];
        }
        return ans;
    }
};

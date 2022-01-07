class Solution{
    public:
    string colName (long long int n)
    {
        string ans="";
        while(n)
        {
            int mod =  n%26;
            if(mod==0)
            {
                mod=26;
                n= n-26;
            }
            ans+=(mod-1+'A');
            n = n/26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

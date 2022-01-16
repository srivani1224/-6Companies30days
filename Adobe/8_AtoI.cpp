class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        int ans = 0;
        int n = s.length(), p=10;
        for(int i=0; i<n ;i++)
        {
            if(i==0)
            {
                if(!((s[i]>='0' && s[i]<='9') || s[i]=='-' || s[i]=='+'))
                    return -1;
            }
            else if(!(s[i]>='0' && s[i]<='9'))
                return -1;
        }
        for(int i= 0; i<n ; i++)
        {
            if(s[i]>='0' && s[i]<='9')
                ans = (ans * p) + (s[i] - '0');
        }
        if(s[0]=='-')
            return -1*ans;
        return ans;
    }
};

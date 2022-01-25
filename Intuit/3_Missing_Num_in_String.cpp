int isValid(const string &s, int n, int l)
{
    if(n <= l)
        return -1;
    int temp=0;
    int L=l;
    int prev=0;
    int ans = -1;
    for(int i=0;i<l;i++)
    {
        prev = prev * 10 + (s[i]-'0');
    }
    for(int i=l;i<n;i++)
    {
        temp = temp * 10 + (s[i]-'0');
        if(temp > prev + 2)
        {
            return -1;
        }
        if(temp == prev + 2)
        {
            if(ans == -1)
            {
                //cout<<ans<<" "<<prev+1<<endl;
                ans = prev + 1;
                prev = temp;
                temp = 0;
            }
            else
                return -1;
        }
        if(temp == prev + 1)
        {
            prev = temp;
            temp = 0;
        }
    }
    return ans;
}

int missingNumber(const string& s)
{
    int n =  s.length();
    for(int i=1;i<=6;i++)
    {
        int x = isValid(s,n,i);
        //cout<<i<<" "<<x<<endl;
        if(x != -1)
            return x;
    }
    return -1;
}

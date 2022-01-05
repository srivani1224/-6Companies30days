class Solution {
public:
    string gcdOfStrings(string a, string b) 
    {
        int n = a.length(), m = b.length();
        if(n<m)
            return gcdOfStrings(b,a);
        string k = "";
        for(int i=0;i<m;i++)
        {
            string ans =  b.substr(0,i+1);
            int l = ans.length(),j;
            for(j=0;j<m;j=j+l)
            {
                if(ans!=b.substr(j,l))
                    break;
            }
            if(j==m)
            {
                for(j=0;j<n;j=j+l)
                {
                    if(ans!=a.substr(j,l))
                        break;
                }
                if(j==n)
                    k = ans;
            }
        }
        return k;
    }
};

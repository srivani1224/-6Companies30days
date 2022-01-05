class Solution
{
public:
    string decodedString(string s)
    {
        stack<string> a;
        int l=0;
        int n = s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]==']')
            {
                string x="";
                while(!a.empty() && a.top()!="[")
                {
                    x+=a.top();
                    a.pop();
                }
                a.pop();
                int m = 0, l=1;
                while(!a.empty() && a.top()[0]>='0' && a.top()[0]<='9')
                {
                    m = (m) + (l*(a.top()[0] - '0'));
                    l = l*10;
                    a.pop();
                }
                string p="";
                for(int j=0;j<m;j++)
                    p+=x;
                a.push(p);
            }
            else
            {
                string x = "";
                x+=s[i];
                a.push(x);
            }
        }
        string ans = a.top();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

class Solution{   
public:
    string printMinNumberForPattern(string s){
        int n = s.length();
        int l=1,c=0;
        string ans="";
        for(int i=0;i<n;i++)
        {
            if(i==0 && s[i]=='I')
            {
                ans+=(l+'0');
                l++;
            }
            if(s[i]=='D')
                c++;
            int j=i+1;
            while(j<n && s[j]=='D')
            {
                j++;
                c++;
            }
            int x = c;
            while(c>=0)
            {
                ans+=(l+c+'0');
                c--;
            }
            i = j-1;
            l += (x+1);
            c=0;
        }
        return ans;
    }
};

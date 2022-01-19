class Solution{
  public:
    string nextPalin(string s) { 
        int n = s.length();
        
        if(n<=3)
            return "-1";
            
        int mid = n/2 - 1,i;
        string x = s.substr(0, mid+1);
        
        for(i=mid-1 ; i>=0; i--)
        {
            if(x[i] < x[i+1])
            {
                for(int j=mid; j>i; j--)
                {
                    if(x[j] > x[i])
                    {
                        swap(x[j], x[i]);
                        break;
                    }
                }
                sort(x.begin()+i+1, x.end());
                break;
            }
        }
        
        if(i==-1)
            return "-1";
            
        string res="";
        res+=x;
        
        if(n%2)
            x+=s[n/2];
        
        reverse(x.begin(), x.end());
        res+=x;
        return res;
    }
};

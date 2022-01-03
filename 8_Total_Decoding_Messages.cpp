class Solution 
{
	public:
	int Z = 1e9+7;
	    int invalid(string s)
	    {
	        if(s[0]=='0')
	            return 1;
	        int n = s.length();
	        for(int i=1;i<n;i++)
	        {
	            //cout<<s[i]<<" "<<s[i-1]<<endl;
	            if(s[i]=='0' && (s[i-1]=='0' ||  s[i-1]>='3'))
	            {
	                return 1;
	            }
	        }
	        return 0;
	    }
		int CountWays(string s)
		{
		    int n = s.length();
		    if(n==0)
		        return 1;
		    if(invalid(s))
		        return 0;
		    long long int a[n];
		    a[0] = 1;
		    for(int i=1;i<n;i++)
		    {
		        if(s[i] == '0')
		        {
		            if(i>1)
		            {
    		            a[i] = a[i-2];
		            }
		            else
		            {
		                a[i] = 1;
		            }
		            continue;
		        }
		        long long int p = a[i-1];
		        long long int x = ((s[i-1]-'0')*10) + (s[i]-'0');
		        if(s[i-1]!='0' && x>=1 && x<=26)
		        {
		            if(i>1)
		                p = (p%Z + (a[i-2])%Z)%Z;
		            else 
		                p++;
		        }
		        a[i]=p;
		    }
		    return a[n-1];
		}

};

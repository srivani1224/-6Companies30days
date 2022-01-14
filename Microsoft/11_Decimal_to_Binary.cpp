vector<string> generate(int n)
{
	vector<string> ans;
	for(int i=1;i<=n;i++)
	{
	    int x=i;
	    string s="";
	    while(x)
	    {
	        s+=((x%2)+'0');
	        x = x/2;
	    }
	    reverse(s.begin(),s.end());
	    ans.push_back(s);
	}
	return ans;
}

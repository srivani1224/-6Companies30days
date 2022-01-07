class Solution {
	public:
		string FirstNonRepeating(string s){
		    int n = s.length();
		    string ans="";
		    int a[26]={0};
		    queue<char> q;
		    for(int i=0;i<n;i++)
		    {
		        if(a[s[i]-'a']==0)
		        {
		            q.push(s[i]);
		        }
		        a[s[i]-'a']++;
		        while(!q.empty() && a[q.front()-'a']>1)
		            q.pop();
		        if(q.empty())
		            ans+='#';
		        else
		            ans+=q.front();
		    }
		    return ans;
		}

};

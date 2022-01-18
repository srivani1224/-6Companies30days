class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    
    
    vector<string> winner(string s[], int n)
    {
        vector<string> ans;
        unordered_map<string, int> m;
        int ma;
        for(int i=0;i<n;i++)
        {
            m[s[i]]++;
            if(ans.size() == 0)
            {
                ans.push_back(s[i]);
                ma = m[s[i]];
            }
            else
            {
                if(m[s[i]] > ma || (m[s[i]] == ma && s[i].compare(ans[0]) < 0))
                {
                    ans[0] = s[i];
                    ma = m[s[i]];
                }
            }
        }
        ans.push_back(to_string(ma));
        return ans;
    }
};

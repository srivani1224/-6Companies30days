class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& v) 
    {
        int n = v.size();
        map<string, vector<string> > m;
        for(int i=0;i<n;i++)
        {
            string s = v[i];
            sort(s.begin(),s.end());
            m[s].push_back(v[i]);
        }
        vector<vector<string> > ans;
        for(auto i : m)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &a, int k) {
        vector<vector<int> > ans;
        int n = a.size();
        sort(a.begin(),a.end());
        set<vector<int> > st;
        
        for(int i=0; i< n-3; i++)
        {
            for(int j=i+1; j< n-2; j++)
            {
                int l = j+1, r = n-1;
                vector<int> v;
                while(l < r)
                {
                    int s = a[i]+a[j]+a[l]+a[r];
                    if(s == k)
                    {
                        st.insert({a[i],a[j],a[l],a[r]});
                        l++;
                        r--;
                    }
                    else if(s < k)
                        l++;
                    else
                        r--;
                }
            }
        }
        for(auto i : st)
            ans.push_back(i);
        return ans;
    }
};

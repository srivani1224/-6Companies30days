class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& v) 
    {
        sort(v.begin(), v.end());
        vector<int> ans;
        while(n--)
        {
            unordered_map<int, int> freq; 
            int d = v[1] - v[0];
            vector<int> ex, in;
            bool flag = false;
            for(auto i : v)
            {
                if(!freq[i])
                {
                    ex.push_back(i);
                    freq[i+d]++;
                    if(i == 0)
                        flag =  true;
                }
                else
                {
                    in.push_back(i);
                    freq[i]--;
                }
            }
            if(flag)
            {
                ans.push_back(d);
                v = ex;
            }
            else
            {
                ans.push_back(-1 * d);
                v = in;
            }
        }
        return ans;
    }
};

class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> v, int n, int k) {
        deque<int> dq;
        vector<int> ans;
        dq.push_back(0);
        for(int i=1;i<k;i++)
        {
            while(!dq.empty() && v[i] >= v[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        ans.push_back(v[dq.front()]);
        for(int i=k;i<n;i++)
        {
            while(!dq.empty() && dq.front()<=i-k)
                dq.pop_front();
            while(!dq.empty() && v[i] >= v[dq.back()])
                dq.pop_back();
            dq.push_back(i);
            ans.push_back(v[dq.front()]);
        }
        return ans;
    }
};

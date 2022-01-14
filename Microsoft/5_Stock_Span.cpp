class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector<int> calculateSpan(int p[], int n)
    {
        vector<int> ans;
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && p[s.top()] <= p[i])
            {
                s.pop();
            }
            if(s.empty())
                ans.push_back(i+1);
            else
                ans.push_back(i-s.top());
            s.push(i);
        }
        return ans;
    }
};

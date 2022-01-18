class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n)
    {
        vector<int> ans;
        stack<int> s;
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && s.top() <= a[i])
                s.pop();
            s.push(a[i]);
            if(s.size() == 1)
                ans.push_back(a[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

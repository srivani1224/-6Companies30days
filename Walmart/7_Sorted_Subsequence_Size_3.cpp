//Method 1 Time : O(n), space : O(n)

class Solution{
  public:
    vector<int> find3Numbers(vector<int> v, int n) 
    {
        vector<int> ans;
        if(n < 3)
            return ans;
        int mi[n], ma[n];
        mi[0] = 0;
        for(int i=1;i<n;i++)
        {
            if(v[i] < v[mi[i-1]])
                mi[i] = i;
            else
                mi[i] = mi[i-1];
        }
        ma[n-1] = n-1;
        for(int i=n-2;i>=0;i--)
        {
            if(v[i] > v[ma[i+1]])
                ma[i] = i;
            else
                ma[i] = ma[i+1];
        }
        for(int i=1;i<n-1;i++)
        {
            if(mi[i]!=i && ma[i]!=i && v[mi[i]] < v[i] && v[i] < v[ma[i]])
            {
                ans.push_back(v[mi[i]]);
                ans.push_back(v[i]);
                ans.push_back(v[ma[i]]);
                return ans;
            }
        }
        return ans;
    }
};

/*
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Method 2     [Time : O(n), space : O(n)]

class Solution{
  public:
    vector<int> find3Numbers(vector<int> v, int n) 
    {
        vector<int> ans;
        if(n < 3)
            return ans;
        stack<int> s;
        for(int i=n-1; i>=0; i--)
        {
            while(!s.empty() && s.top() <= v[i])
            {
                s.pop();
            }
            s.push(v[i]);
            if(s.size() == 3)
                break;
        }
        if(s.size() == 3)
        {
            ans.push_back(s.top());
            s.pop();
            ans.push_back(s.top());
            s.pop();
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  // Method 3    [Time : O(n), Space : O(1)]
  
  class Solution{
  public:
    vector<int> find3Numbers(vector<int> v, int n) 
    {
        vector<int> ans;
        if(n < 3)
            return ans;
        int prev=v[0], curr=-1, next = -1;
        for(int i=0; i<n; i++)
        {
            if(curr!=-1 && next!=-1)
                break;
            if(v[i] < prev && curr == -1)
                prev = v[i];
            else if(v[i] > prev && ( curr == -1 || v[i] < curr) )
                curr = v[i];
            else if(v[i] > curr && curr != -1 && next == -1)
                next = v[i];
        }
        if(curr!=-1 && next!=-1)
        {
            ans.push_back(prev);
            ans.push_back(curr);
            ans.push_back(next);
        }
        return ans;
    }
};
*/

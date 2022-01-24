class Solution {
public:
    bool check(vector<int>& v, int d, int c)
    {
        int s=0, D=0;
        int n = v.size();
        for(int i=0;i<n;i++)
        {
            s+=v[i];
            if(s > c)
            {
               D++;
               s = v[i]; 
            }
            if(D >= d)
                return false;
        }
        return true;
    }
    
    int shipWithinDays(vector<int>& v, int d) 
    {
        int l = INT_MIN;
        int r = 0;
        int n = v.size();
        for(int i=0;i<n;i++)
        {
            l = max(l,v[i]);
            r += v[i];
        }
        int ans;
        while(l<=r)
        {
            int m = l + (r-l)/2;
            if(check(v,d,m))
            {
                ans = m;
                r = m-1;
            }
            else
            {
                l = m+1;
            }
        }
        return ans;
    }
};

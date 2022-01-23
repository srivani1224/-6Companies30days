class Solution {
public:
    int minEatingSpeed(vector<int>& v, int h) 
    {
        int ma = -1, mi = 1;
        int n =  v.size();
        for(int i=0;i<n;i++)
            ma = max(ma, v[i]);
        int ans = ma;
        while(mi <= ma)
        {
            int c = 0;
            int mid = mi + (ma - mi)/2;
            for(int i=0; i<n; i++)
            {
                c += (v[i]/mid);
                if(v[i] % mid)
                    c++;
            }
            if(c > h)
            {
                mi =  mid + 1;
            }
            else 
            {
                ans = mid;
                ma = mid - 1;
            }
        }
        return ans;
    }
};

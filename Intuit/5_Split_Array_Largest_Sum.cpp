class Solution {
public:
    bool isValid(vector<int>& v, int n, int m, int X)
    {
        int s=0;
        for(int i=0;i<n;i++)
        {
            s += v[i];
            if(s > X)
            {
                s = v[i];
                m--;
            }
        }
        return (m >= 0 && s<=X) ? true : false;
    }
    
    int splitArray(vector<int>& v, int m) {
        int n = v.size();
        int mi =  INT_MIN, ma = 0;
        for(int i=0;i<n;i++)
        {
            mi = max(mi, v[i]);
            ma += v[i];
        }
        int ans = ma;
        while(mi <= ma)
        {
            int mid = mi + (ma-mi)/2;
            if(isValid(v,n,m-1,mid))
            {
                ans = mid;
                //cout<<ans<<endl;
                ma = mid - 1;
            }
            else
            {
                mi = mid + 1;
            } 
        }
        return ans;
    }
};

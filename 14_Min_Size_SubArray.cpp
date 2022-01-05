class Solution {
public:
    int minSubArrayLen(int k, vector<int>& v) {
        int n = v.size();
        int mi = INT_MAX;
        int i=0, s=0;
        for(int j=0;j<n;j++)
        {
            s+=v[j];
            if(s>=k)
            {
                while(i<=j && (s-v[i])>=k)
                {
                    s=s-v[i];
                    i++;
                }
                mi = min(mi, j-i+1);
            }
        }
        return (mi==INT_MAX)?0:mi;
    }
};

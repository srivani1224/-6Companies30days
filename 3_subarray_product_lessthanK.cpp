class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) 
    {
        long long int ans=0, i=0, j=0, p=1;;
        while(i<n && j<n)
        {
            if(j<i)
            {
                j=i;
                continue;
            }
            if((p*a[j]) < k)
            {
                p=p*a[j];
                j++;
                ans+=(j-i);
            }
            else
            {
                if(j>i)
                {
                    p = p/a[i];
                }
                i++;
            }
        }
        return ans;
    }
};

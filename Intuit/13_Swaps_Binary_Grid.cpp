class Solution {
public:
    int minSwaps(vector<vector<int>>& v) 
    {
        int n = v.size();
        vector<int> a(n,-1);
        for(int i=0;i<n;i++)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(v[i][j] == 1)
                {
                    a[i] = j;
                    break;
                }
            }
        }
        bool flag = true;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(a[i] > i)
            {
                flag = false;
                for(int j=i+1;j<n;j++)
                {
                    if(a[j] <= i)
                    {
                        flag = true;
                        for(int k=j;k>i;k--)
                        {
                            swap(a[k],a[k-1]);
                            ans++;
                        }
                        break;
                    }
                }
            } 
            if(flag == false)
                return -1;
        }
        return ans;
    }
};

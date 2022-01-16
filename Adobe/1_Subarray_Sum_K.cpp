class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int a[], int n, long long s)
    {
       long long x = 0;
       int i=0,j=0;
       vector<int> ans;
       while(j<n)
       {
            if(x + a[j] == s)
            {
                ans.push_back(i+1);
                ans.push_back(j+1);
                return ans;
            }
            else if(x + a[j] < s)
            {
                x += a[j];
                j++;
            }
            else
            {
                x -= a[i];
                i++;
            }  
       }
       ans.push_back(-1);
       return ans;
    }
};

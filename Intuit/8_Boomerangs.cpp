class Solution {
public:
    double dis(vector<int> a, vector<int> b)
    {
        int x1 = a[0];
        int y1 = a[1];
        int x2 = b[0];
        int y2 = b[1];
        return sqrt(((x2 - x1) * (x2 -  x1)) + ((y2 - y1) * (y2 -  y1)));
    }
    int numberOfBoomerangs(vector<vector<int>>& v) 
    {
        int n = v.size(), ans = 0;
        if(n<=2)
            return 0;
        for(int i=0;i<n;i++)
        {
            map<double, int> m;
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    //cout<<dis(v[i],v[j])<<endl;
                    m[dis(v[i],v[j])]++;
                }
            }
            for(auto x : m)
            {
                //cout<<x.second<<endl;
                int p = x.second;
                ans += ((p*(p-1))/2);
            }
        }
        return 2*ans;
    }
};

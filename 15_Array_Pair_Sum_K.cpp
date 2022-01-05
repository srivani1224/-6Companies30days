class Solution {
  public:
    bool canPair(vector<int> v, int k) {
        int n = v.size();
        if(n%2)
            return false;
        map<int,int> m;
        for(int i=0;i<n;i++)
        {
            if(v[i]>=k)
            {
                v[i] -= (k*(v[i]/k));
            }
            m[v[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(m[v[i]] == 0)
                continue;
            if(m[(k-v[i])%k]<=0 || m[v[i]]<0)
                return false;
            else
            {
                m[v[i]]--;
                m[(k-v[i])%k]--;
            }
        }
        return true;
    }
};

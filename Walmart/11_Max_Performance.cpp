class Solution {
public:
    int Z = 1e9+7;
    
    int maxPerformance(int n, vector<int>& s, vector<int>& e, int k) 
    {
        vector<pair<int,int> > v;
        priority_queue<long long, vector<long long>, greater<long long> > pq;
        for(int i=0;i<n;i++)
            v.push_back({e[i], s[i]});
        sort(v.rbegin(), v.rend());
        long long int x = 0, ans = -1;
        for(int i=0;i<n;i++)
        {
            pq.push(v[i].second);
            x = (x + v[i].second);
            if(pq.size() > k)
            {
                x -= pq.top();
                pq.pop();
            }
            ans = max(ans, (v[i].first * x));
        }
        return ans % Z;    
    }
};

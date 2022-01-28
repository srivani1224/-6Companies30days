class Solution{
    public:
    //You need to complete this fucntion
    const int Z = 1e9+7;
    long long power(int n ,int x)
    {
        if(x == 0 || n == 0)
            return 0;
        if(x == 1 || n == 1)
            return n;
        long long k = power(n, x/2) % Z;
        long long ans = (k * k) % Z;
        if(x%2)
            ans = (ans * n) % Z;
        return ans;
    }

};

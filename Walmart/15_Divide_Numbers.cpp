class Solution {
public:
    int divide(int A, int B) 
    {
        if(A == 0)
            return 0;
        int sign = (A < 0) ^ (B < 0);
        long long a = abs(A);
        long long b = abs(B);
        long long int ans = 0, ct = 1;
        while(b <= a)
        {
            ans += ct;
            a -= b;
            ct = ct<<1;
            b =  b<<1;
        }   
        B = abs(B);
        while(B <= a)
        {
            ans++;
            a -= B;
        }
        if(sign)
            ans = -1 * (ans);
        if(ans < -2147483648)
            return -2147483648;
        if(ans > 2147483647)
            return 2147483647;
        return ans;
    }
};

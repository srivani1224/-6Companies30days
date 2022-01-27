class Solution 
{
public:
    static bool cmp(string &a, string &b)
    {
        int n = a.length();
        int m = b.length();
        if(n == m)
            return a > b;
        return n > m;
    }
    
    string kthLargestNumber(vector<string>& s, int k)
    {
        sort(s.begin(), s.end(), cmp);
        return s[k-1];
    }
};

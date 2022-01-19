class Solution
{
    public:
    
    void fun(int n, vector<string> &ans, int x, int y, string s)
    {
        cout<<s<<endl;
        if(x==n && y==n)
        {
            ans.push_back(s);
            return ;
        }
        if(x < n)
            fun(n,ans,x+1,y,s+'(');
        if(y < x)
            fun(n,ans,x,y+1,s+')');
    }
    vector<string> AllParenthesis(int n) 
    {
        vector<string> ans;
        fun(n, ans, 0, 0, "");
        return ans;
    }
};

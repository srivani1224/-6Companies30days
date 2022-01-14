class Solution
{
    public:
    string x[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    void helper(int a[], int i, int n,string s, vector<string> &ans)
    {
        if(i>=n)
        {
            ans.push_back(s);
            return;
        }
        int ind = a[i];
        for(int j=0;j<x[ind].length();j++)
        {
            helper(a,i+1,n,s+x[ind][j],ans);
        }
    }
    vector<string> possibleWords(int a[], int n)
    {
        vector<string> ans;
        string s="";
        helper(a,0,n,s,ans);
        return ans;
    }
};

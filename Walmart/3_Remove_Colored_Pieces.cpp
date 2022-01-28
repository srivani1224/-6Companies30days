class Solution {
public:
    bool winnerOfGame(string s) {
        
        int n = s.length();
        if(n<=2)
            return false;
        
        int a=0, b=0;
        
        for(int i=1; i<n-1; i++)
        {
            if(s[i-1] == 'A' && s[i+1] == 'A' && s[i] == 'A')
                a++;
            if(s[i-1] == 'B' && s[i+1] == 'B' && s[i] == 'B')
            {
                b++;
            }
        }
        return (a > b) ? true : false;
    }
};

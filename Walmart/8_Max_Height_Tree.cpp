// (n * (n+1) ) / 2 = sum 

class Solution{
public:
    int height(int n){
        return (-1 + sqrt(1 + (8 * n))) / 2;
    }
};

class Solution {
  public:
    int findPosition(int N , int M , int K) {
        return (((K+M-1)%N)==0)?N:(K+M-1)%N;
    }
};

class Solution{
public:
    int minSteps(int D){
       D = abs(D);
       int sum =0 , step =0;
       while(sum < D || ((sum - D) % 2 == 1))
       {
           step++;
           sum+=step;
       }
       return step;
    }
};

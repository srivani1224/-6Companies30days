class Solution{
public: 
    string s;
    void printParenthesis(int i, int j, int n, int *a, char &name){
    	if (i == j){
    		s += name;
    		name++;
    		return;
    	}
    	s += '(';
    	printParenthesis(i, *((a+i*n)+j), n, a, name);
    	printParenthesis(*((a+i*n)+j) + 1, j, n, a, name);
    	s += ')';
    }
    string matrixChainOrder(int p[], int n){
        int c[n-1][n-1]={0}, a[n-1][n-1]={0};
        for(int d=1;d<n-1;d++)
        {
            for(int i=0,j=i+d;i<n-1 && j<n-1;i++,j++)
            {
                int ans = INT_MAX, ind =  -1;
                for(int k=i;k<j;k++)
                {
                    int x = c[i][k]+c[k+1][j]+(p[i]*p[k+1]*p[j+1]);
                    if(x<ans)
                    {
                        ans =  x;
                        ind = k;
                    }
                }
                c[i][j] = ans;
                a[i][j] = ind;
            }
        }
        char name = 'A';
    	printParenthesis(0, n-2, n-1, (int *)a, name);
    	return s;
    }
};

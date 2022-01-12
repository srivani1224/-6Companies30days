void rotate(vector<vector<int> >& v)
{
    int n = v.size();
    for(int k=0;k<n/2;k++)
    {
        for(int i=k;i<n-k-1;i++)
        {
            int x = v[k][i];
            v[k][i] = v[i][n-k-1];
            v[i][n-k-1] = v[n-k-1][n-i-1];
            v[n-k-1][n-i-1] = v[n-i-1][k];
            v[n-i-1][k] = x;
        }
    }
}

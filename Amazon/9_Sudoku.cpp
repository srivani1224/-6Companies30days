class Solution{
public:
    int isValid(vector<vector<int>> v)
    {
        int x[10]={0};
        for(int i=0;i<9;i++)
        {
            memset(x,0,sizeof(x));
            for(int j=0;j<9;j++)
            {
                if(v[i][j]>0 && x[v[i][j]]>0)
                {
                    //cout<<i<<" "<<j<<" "<<v[i][j]<<" "<<x[v[i][j]]<<endl;
                    return 0;
                }
                x[v[i][j]]++;
            }
        }
        //cout<<"HI"<<endl;
        for(int i=0;i<9;i++)
        {
            memset(x,0,sizeof(x));
            for(int j=0;j<9;j++)
            {
                if(v[j][i]>0 && x[v[j][i]]>0)
                    return 0;
                x[v[j][i]]++;
            }
        }
        //cout<<"HI"<<endl;
        for(int i=0;i<9;i=i+3)
        {
            for(int j=0;j<9;j=j+3)
            {
                memset(x,0,sizeof(x));
                for(int k=i;k<i+3;k++)
                {
                    for(int l=j;l<j+3;l++)
                    {
                       if(v[k][l]>0 && x[v[k][l]]>0)
                            return 0;
                        x[v[k][l]]++; 
                    }
                }
            }
        }
        return 1;
    }
};

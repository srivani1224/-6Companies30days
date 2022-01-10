class Solution {
public:
    int l[4] = {1, -1, 0, 0};
    int r[4] = {0, 0, 1, -1};
    bool isValid(int x, int y, int n, int m)
    {
        if(x>=0 && y>=0 && x<n && y<m)
                return true;
        return false;
    }
    int orangesRotting(vector<vector<int>>& v) 
    {
        int n = v.size(), m = v[0].size();
        queue<pair<int,int> > q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        q.push({-1,-1});
        int cnt=0;
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(x==-1 && y==-1 && q.size()>0)
            {
                cnt++;
                q.push({-1,-1});
            }
            else
            {
                for(int i=0;i<4;i++)
                {
                    if((isValid(x+l[i],y+r[i],n,m)) && v[x+l[i]][y+r[i]]==1)
                    {
                        v[x+l[i]][y+r[i]]=2;
                        q.push({x+l[i],y+r[i]});
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return cnt;
    }
};

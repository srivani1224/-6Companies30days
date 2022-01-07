class Solution {
public:
    int longestMountain(vector<int>& v) {
        int n =  v.size();
        int ma = 0, l=0, p=-1;
        for(int i=1;i<n;i++)
        {
            if(v[i]>v[i-1])
            {
                if(p!=-1)
                {
                    ma = max(ma, (i-l));
                    l=i-1;
                    p=-1;
                }
            }
            else if(v[i] == v[i-1])
            {
                if(p==-1)
                    l=i;
                else
                {
                    ma = max(ma, (i-l));
                    l=i;
                    p=-1;
                }
            }
            else
            {
                if(p==-1)
                {
                    if(l==i-1)
                        l=i;
                    else
                    {
                        p=i-1;
                    }
                }
            }
        }
        if(p!=-1)
            ma = max(ma, (n-l));
        return (ma>=3)?ma:0;
    }
};

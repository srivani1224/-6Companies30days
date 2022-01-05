class Solution{
public:
    int *findTwoElement(int *a, int n) {
        long long int s1=0,s2=0;
        for(int i=0;i<n;i++){
            s1=(long long)s1+(long long)a[i];
            s2=(long long)s2+((long long)a[i]*(long long)a[i]);
        }
        long long int a1=0,a2=0;
        for(int i=1;i<=n;i++){
            a1=(long long)a1+(long long)i;
            a2=(long long)a2+((long long)i*(long long)i);
        }
        long long int m1,m2,m3;
        int *ans = new int[2];
        m1=(long long)a1-(long long)s1;
        m2=(long long)a2-(long long)s2;
        m3=(long long)m2/(long long)m1;
        ans[0] = (m3-m1)/2;
        ans[1] = (m3+m1)/2;
        return ans;
    }
};

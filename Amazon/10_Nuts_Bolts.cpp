class Solution{
public:	
    int partition(char a[],int l, int h, char pivot)
    {
        int i = l;
        char t1,t2;
        for(int j=l;j<h;j++)
        {
            if(a[j]<pivot)
            {
                t1=a[i];
                a[i]=a[j];
                a[j]=t1;
                i++;
            }
            else if(a[j]==pivot)
            {
                t1=a[j];
                a[j]=a[h];
                a[h]=t1;
                j--;
            }
        }
        t2=a[i];
        a[i]=a[h];
        a[h]=t2;
        return i;
    }
    void quick_sort(char nuts[], char bolts[],int l, int h)
    {
        if(l<h)
        {
            int pivot = partition(nuts,l,h,bolts[h]);
            quick_sort(nuts,bolts,l,pivot-1);
            quick_sort(nuts,bolts,pivot+1,h);
            pivot = partition(bolts,l,h,nuts[pivot]);
            quick_sort(nuts,bolts,l,pivot-1);
            quick_sort(nuts,bolts,pivot+1,h);
        }
    }
	void matchPairs(char nuts[], char bolts[], int n) {
	    quick_sort(nuts,bolts,0,n-1);
	}

};

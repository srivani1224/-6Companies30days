struct HeapNode
{
    int ele;
    int i;
    int j;
};

class Solution{
    public:
    
    HeapNode * harr;
    int heap_size;
    
    void minHeap(HeapNode a[], int size)
    {
        heap_size = size;
        harr = a;
        int i = (heap_size - 1) / 2;
        while(i>=0)
        {
            minHeapify(i);
            i--;
        }
    }
    
    void minHeapify(int i)
    {
        int l = left(i), r = right(i);
        int smallest = i;
        
        if (l < heap_size && harr[l].ele < harr[i].ele)
            smallest = l;
            
        if (r < heap_size && harr[r].ele < harr[smallest].ele)
            smallest = r;
            
        if (smallest != i) 
        {
            swap(harr[i], harr[smallest]);
            minHeapify(smallest);
        }
        
    }
    
    int left(int i)
    {
        return (2*i + 1);
    }
    
    int right(int i)
    {
        return (2*i + 2);
    }
    
    HeapNode getMin()
    {
        return harr[0];
    }
    
    void replaceMin(HeapNode x)
    {
        harr[0] = x;
        minHeapify(0);
    }
    
    pair<int,int> findSmallestRange(int a[][N], int n, int k)
    {
        int ans_mi = INT_MAX , ans_ma = INT_MIN, ans = INT_MAX ;
        int p[k] = {0};
        int ind = -1;
        int mi = INT_MAX;
        int ma = INT_MIN;
        bool flag = false;
        
        HeapNode* harr = new HeapNode[k];
        for(int i=0;i<k;i++)
        {
            harr[i].ele = a[i][0];
            harr[i].i = i;
            harr[i].j = 1;
            
            ma = max(ma, harr[i].ele);
        }
        
        Solution hp;
        hp.minHeap(harr, k);
        
        while(1)
        {
            HeapNode root = hp.getMin();
            mi = hp.getMin().ele;
            
            if(ma - mi < ans)
            {
                ans = ma - mi;
                ans_ma = ma;
                ans_mi = mi;
            }
            
            if(root.j < n)
            {
                root.ele = a[root.i][root.j];
                root.j += 1;
                
                ma = max(ma, root.ele);
            }
            
            else
                break;
            
            hp.replaceMin(root);
            
        }
        return {ans_mi, ans_ma};
    }
};

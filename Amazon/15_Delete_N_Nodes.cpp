class Solution
{
    public:
    void linkdelete(struct Node *root, int m, int n)
    {
        struct Node *temp = root;
        int  M=0,N=0;
        while(root)
        {
            M++;
            temp = root;
            root = root->next;
            if(m == M)
            {
                M=0;
                while(root)
                {
                    if(n == N)
                        break;
                    N++;
                    root = root->next;
                }
                if(temp)
                    temp->next = root;
                N=0;
            }
        }
    }
};

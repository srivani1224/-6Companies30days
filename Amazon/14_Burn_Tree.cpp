class Solution {
  public:
    struct test
    {
        Node* p = NULL;
        Node* l = NULL;
        Node* r = NULL;
    };
    Node* T = NULL;
    void fun(Node* root, map< Node* , test > &m, Node* node, int t)
    {
        if(root == NULL)
            return;
        if(root->data == t && !T)
        {
            T = root;
        }
        m[root].p = node;
        m[root].l = root->left;
        m[root].r = root->right;
        fun(root->left,m,root,t);
        fun(root->right,m,root,t);
    }
    int helper(Node* root, map<Node* , bool> &flag, map< Node* , test > &m)
    {
        if(!root || flag[root])
            return 0;
        flag[root]=true;
        int x=0;
        return 1 + max(helper(m[root].p,flag,m), max(helper(m[root].l,flag,m), helper(m[root].r,flag,m)));
    }
    int minTime(Node* root, int target) 
    {
        map< Node* , test > m;
        Node* node =  NULL;
        T = NULL;
        fun(root,m,node,target);
        int c=0;
        map<Node* , bool> flag;
        return helper(T,flag,m)-1;
    }
};

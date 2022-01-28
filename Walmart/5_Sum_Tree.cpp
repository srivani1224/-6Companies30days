class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int fun(Node *node)
    {
        if(node == NULL)
            return 0;
        int x = fun(node->left);
        int y = fun(node->right);
        
        int temp = node -> data;
        node -> data = x + y;
        return temp + x + y;
    }
    
    void toSumTree(Node *node)
    {
        fun(node);
    }
};

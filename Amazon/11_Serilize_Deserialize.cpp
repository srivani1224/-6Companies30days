class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    void helper(Node *root, vector<int> &v)
    {
        if(root==NULL)
            return;
        helper(root->right,v);
        v.push_back(root->data);
        helper(root->left,v);
        return ;
    }
    vector<int> serialize(Node *root) 
    {
        vector<int> v;
        helper(root, v);
        return v;
    }
    
    //Function to deserialize a list and construct the tree.
    int i=0;
    Node * deSerialize(vector<int> &A)
    {
       if(i>=A.size() || A[i]==-1)
       {
           i++;
           return NULL;
       }
       //cout<<A[i]<<" ";
       Node* root = new Node(A[i++]);
       root->left = deSerialize(A);
       root->right = deSerialize(A);
       return root;
    }

};

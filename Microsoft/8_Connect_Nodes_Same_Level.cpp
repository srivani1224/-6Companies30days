class Solution
{
    public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
       queue<Node*> q;
       q.push(root);
       while(!q.empty())
       {
           int n = q.size();
           for(int i=0;i<n;i++)
           {
                Node* temp  = q.front();
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                if(i+1 == n)
                    temp -> nextRight = NULL;
                else
                    temp -> nextRight = q.front();
           }
       }
    }    
      
};

/* Method 2

class Solution
{
    public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
       queue<Node*> q;
       q.push(root);
       Node *prev = NULL;
       q.push(NULL);
       while(!q.empty())
       {
            Node* temp  = q.front();
            if(prev)
                prev->nextRight =  temp;
            prev = temp;
            q.pop();
            if(temp)
            {
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            else
            {
                if(!q.empty())
                    q.push(NULL);
            }
       }
    }    
      
};

*/

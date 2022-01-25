/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* fun(vector<vector<int>>& v, int r_s, int r_e, int c_s, int c_e, int f)
    {
        int s=0;
        for(int i=r_s;i<r_e;i++)
        {
            for(int j=c_s;j<c_e;j++)
                s+=v[i][j];
        }
        Node* ans;
        if(s == 0)
            ans = new Node(false, true);
        else if(s == (f*f))
            ans = new Node(true, true);
        else
        {
            ans = new Node(false,  false);
            f = f/2;
            ans->topLeft     =  fun(v, r_s, r_s+f, c_s, c_s+f, f);
            ans->topRight    =  fun(v, r_s, r_s+f, c_s+f, c_e, f);
            ans->bottomLeft  =  fun(v, r_s+f, r_e, c_s, c_s+f, f);
            ans->bottomRight =  fun(v, r_s+f, r_e, c_s+f, c_e, f);
        }
        return ans;
    }
   
    Node* construct(vector<vector<int>>& v) 
    {
        int n = v.size();
        return fun(v,0,n,0,n,n);
    }
};

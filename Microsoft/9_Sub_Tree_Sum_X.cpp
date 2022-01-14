int helper(Node* root, int X, int &cnt)
{
    if(root == NULL)
        return 0;
    int sum = root->data + helper(root->left, X, cnt) + helper(root->right, X, cnt);
    if(sum == X)
        cnt++;
    return sum;
}

int countSubtreesWithSumX(Node* root, int X)
{
    int cnt = 0;
    helper(root, X, cnt);
    return cnt;
}

bool checkBalanced(TreeNode* root, int& height)
{
    if(NULL == root) return true;

    int left_height =  height+1;
    int right_height = height+1;
    bool left_balance = checkBalanced(root->left, left_height);
    bool right_balance = checkBalanced(root->right, right_height) 
    height = (left_height > right_height ? left_height : right_height);
    return left_balance && right_balance&& abs(left_height-right_height) <= 1;
}

bool isBalanced(TreeNode* root)
{
    int h = 0;
    return checkBalanced(root, h);
}


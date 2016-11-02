bool isSymmetric(TreeNode* root)
{
    if(NULL == root) return true;

    vector<TreeNode*> v; v.push_back(root);
    while(!v.empty())
    {
	int i, j;
	for(i=0,j=v.size()-1; i< j; i++,j--)
	{
	    if(NULL == v[i] && NULL == v[j]) continue;
	    if(NULL == v[i] || NULL == v[j]) return false;
	    if(v[i]->val != v[j]->val) return false;
	}

	vector<TreeNode*> next_level;
	for(i = 0; i< v.size(); i++)
	{
	    if(NULL != v[i]) { next_level.push_back(v[i]->left); next_level.push_back(v[i]->right); }
	}
	v = next_level;
    }

    return true;
}

bool check(TreeNode* left, TreeNode* right)
{
    if(NULL == left && NULL == right) return true;

    if(NULL == left || NULL == right) return false;

    if(left->val != right->val) return false;

    return check(left->left, right->right)&&check(left->right, right->left);
}

bool isSymmetric(TreeNode* root)
{
    return (NULL == root) || check(root->left, root->right);
}

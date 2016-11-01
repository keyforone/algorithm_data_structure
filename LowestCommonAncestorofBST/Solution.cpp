TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if(NULL == root || NULL == p || NULL == q) return NULL;

    TreeNode* small, large;
    if(p->val <= q->val) { small = p; large = q; }
    else { small = q; large = p; }

    while(true)
    {
	if(root->val > large->val) { root = root->left; continue; }
	if(root->val < small->val) { root = root->right; continue; }

	return root;
    }
}

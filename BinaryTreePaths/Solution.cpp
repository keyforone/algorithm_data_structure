void createTreePaths(TreeNode* root, string path, vector<string>& paths)
{
    stringstream ss;
    ss << root->val;
    path.append(ss.str());

    if(NULL != root->left)
	createTreePaths(root->left, path+"->", paths);
    if(NULL != root->right)
	createTreePaths(root->right, path+"->", paths);

    if(NULL == root->left && NULL == root->right) paths.push_back(path); 
}

vector<string> binaryTreePaths(TreeNode* root)
{
    vector<string> paths;
    string path;

    if(NULL == root) return paths;

    createTreePaths(root, path, paths);

    return paths;
}

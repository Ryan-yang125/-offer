// 简洁优美的递归
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution
{
public:
    int TreeDepth(TreeNode *pRoot)
    {
        return dfs(pRoot);
    }
    int dfs(TreeNode *node)
    {
        if (!node)
            return 0;
        return max(dfs(node->left), dfs(node->right)) + 1;
    }
};
// 递归
class Solution
{
public:
    bool IsBalanced_Solution(TreeNode *pRoot)
    {
        if (!pRoot)
            return true;
        if (dfs(pRoot) == -1)
            return false;
        return true;
    }
    int dfs(TreeNode *node)
    {
        if (!node)
            return 0;
        int lh = dfs(node->left);
        int lr = dfs(node->right);
        if (lh == -1 || lr == -1)
            return -1;
        if (lh - lr > 1 || lr - lh > 1)
            return -1;
        else
            return max(lh, lr) + 1;
    }
};
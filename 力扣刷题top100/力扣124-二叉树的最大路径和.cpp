#include<iostream>


using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxPathSum(TreeNode* root) {

        getMaxGain(root);
        return res;
    }
private:
    int res = INT_MIN;

    //以该节点为根节点的子树中寻找以该节点为起点的一条路径，使得该路径上的节点值之和最大。
    int getMaxGain(TreeNode* node) {

        if (node == NULL) return 0;

        // 只有在最大贡献值大于 0 时，才会选取对应子节点
        int left_gain = max(0, getMaxGain(node->left));
        int right_gain = max(0, getMaxGain(node->right));

        // 判断在该节点包含左右子树的路径和是否大于当前最大路径和
        res = max(res, left_gain + right_gain + node->val);

        // 返回节点的最大贡献值
        return max(left_gain, right_gain) + node->val;
    }
};


int main() {

	system("pause");
	return 0;
}
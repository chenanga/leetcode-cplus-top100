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

    //�Ըýڵ�Ϊ���ڵ��������Ѱ���Ըýڵ�Ϊ����һ��·����ʹ�ø�·���ϵĽڵ�ֵ֮�����
    int getMaxGain(TreeNode* node) {

        if (node == NULL) return 0;

        // ֻ���������ֵ���� 0 ʱ���Ż�ѡȡ��Ӧ�ӽڵ�
        int left_gain = max(0, getMaxGain(node->left));
        int right_gain = max(0, getMaxGain(node->right));

        // �ж��ڸýڵ��������������·�����Ƿ���ڵ�ǰ���·����
        res = max(res, left_gain + right_gain + node->val);

        // ���ؽڵ�������ֵ
        return max(left_gain, right_gain) + node->val;
    }
};


int main() {

	system("pause");
	return 0;
}
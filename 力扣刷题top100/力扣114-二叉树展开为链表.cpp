#include<iostream>
#include<queue>
#include<stack>
using namespace std;

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
 // class Solution {
 // public:
 //     void flatten(TreeNode* root) {
 //         if (root == NULL) return;

 //         preOrder(root);
 //         stk.pop();
 //         while(!stk.empty()) {

 //             root->left = NULL;
 //             root->right = stk.front();
 //             stk.pop();
 //             root = root->right;
 //         }

 //         return;
 //     }
 // private:
 //     queue<TreeNode*> stk;

 //     void preOrder(TreeNode* root) {
 //         if (root == NULL) return;
 //         stk.push(root);
 //         preOrder(root->left);
 //         preOrder(root->right);
 //         return;
 //     }
 // };

 //µü´úÊµÏÖ
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == NULL) return;

        stack<TreeNode*>stk;
        stk.push(root);

        TreeNode* pre = NULL;
        while (!stk.empty()) {
            TreeNode* cur = stk.top();

            if (pre) {
                pre->left = NULL;
                pre->right = cur;
            }
            stk.pop();
            if (cur->right)
                stk.push(cur->right);
            if (cur->left)
                stk.push(cur->left);

            pre = cur;
        }


        return;
    }

};

int main() {

	system("pause");
	return 0;
}
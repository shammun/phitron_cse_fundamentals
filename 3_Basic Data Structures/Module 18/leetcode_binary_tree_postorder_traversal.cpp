/*

https://leetcode.com/problems/binary-tree-postorder-traversal/description/

*/

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorder(root, result);
        return result;
    }

public:
    void postorder(TreeNode* node, vector<int> &result){
        if(node == NULL){
            return;
        }
        postorder(node->left, result);
        postorder(node->right, result);
        result.push_back(node->val);
    }

};
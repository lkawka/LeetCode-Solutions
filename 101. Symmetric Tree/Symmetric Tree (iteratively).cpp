/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        
        queue<TreeNode*> leftQueue, rightQueue;
        
        leftQueue.push(root->left);
        rightQueue.push(root->right);
        
        while(!leftQueue.empty() && !rightQueue.empty()) {
            TreeNode* left = leftQueue.front();
            leftQueue.pop();
            
            TreeNode* right = rightQueue.front();
            rightQueue.pop();
            
            if(left == NULL && right == NULL)
                continue;
            else if(left == NULL || right == NULL)
                return false;
            else if(left->val != right->val)
                return false;
            
            leftQueue.push(left->left);
            leftQueue.push(left->right);
                    
            rightQueue.push(right->right);
            rightQueue.push(right->left);
        }
        return true;
    }
};
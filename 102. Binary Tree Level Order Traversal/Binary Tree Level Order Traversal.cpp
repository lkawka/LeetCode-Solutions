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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> solution;
        
        queue<pair<TreeNode*, int> > q;
        q.push({root, 0});
        
        while(!q.empty()) {
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();
            
            if(node == NULL)
                continue;
            
            while(solution.size() <= level)
                solution.push_back(vector<int>());
            solution[level].push_back(node->val);
            
            q.push({node->left, level+1});
            q.push({node->right, level+1});
        }
        
        return solution;
        
    }
};
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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>bfs;
        int level = 0, max_sum = root->val, ans = 1;
        bfs.push(root);
        while (!bfs.empty()){
            level++;
            int layerSize = bfs.size(), cur_sum = 0;
            for (int i = 0; i < layerSize; ++i){
                TreeNode* cur = bfs.front();
                bfs.pop();
                cur_sum+=cur->val;
                if (cur->left) bfs.push(cur->left);
                if(cur->right) bfs.push(cur->right);
            }
            if (cur_sum > max_sum) {
                max_sum = cur_sum;
                ans = level;
            }
        }
        return ans;
    }
};
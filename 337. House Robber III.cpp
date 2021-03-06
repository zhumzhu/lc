/*The thief has found himself a new place for his thievery again. There is only one entrance to this area, 
called the "root."Besides the root, each house has one and only one parent house. After a tour, the smart thief 
realized that "all houses in this place forms a binary tree". It will automatically contact the police if two 
directly-linked houses were broken into on the same night.
Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:
     3
    / \
   2   3
    \   \ 
     3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.

Example 2:
     3
    / \
   4   5
  / \   \ 
 1   3   1
Maximum amount of money the thief can rob = 4 + 5 = 9.*/

/* 把已经算过的节点用哈希表保存起来，以后递归调用的时候，先在哈希表里找，
如果存在直接返回，如果不存在，等计算出来后，保存到哈希表中再返回，这样方便以后再调用 */

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
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> m;
        return dfs(root, m);
    }
    int dfs(TreeNode *root, unordered_map<TreeNode*, int> &m){
        if(!root) return 0;
        if(m.count(root)) return m[root];
        int val = root->val;
        if(root->left) {
             val += dfs(root->left->left, m) + dfs(root->left->right, m);
        }
        if(root->right) {
             val += dfs(root->right->left, m) + dfs(root->right->right, m);
        }
        val = max(val, dfs(root->left, m) + dfs(root->right,m));
        m[root] = val;
        return val;
    }
};






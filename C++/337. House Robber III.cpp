// problem - 337. House Robber III

/*
    The thief has found himself a new place for his thievery again. There is only 
    one entrance to this area, called the "root." Besides the root, each house has one 
    and only one parent house. After a tour, the smart thief realized that "all houses 
    in this place forms a binary tree". It will automatically contact the police if two 
    directly-linked houses were broken into on the same night.

    Determine the maximum amount of money the thief can rob tonight without alerting the police.
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
#include <unordered_map>
class Solution {
    // using dynamic programming
    // TreeNode* -> <parentLooted, parentNotLooted>
    unordered_map<TreeNode*, pair<int, int>> rec;
public:
    int maxLoot(TreeNode* root, bool isParentLooted) {
        if(root == nullptr) return 0;
        // if in map(dynamic programming)
        if(rec[root].first && isParentLooted) return rec[root].first;
        if(rec[root].second && !isParentLooted) return rec[root].second;
        
        int res = 0;
        if(isParentLooted) {
            res = maxLoot(root->left, false) + maxLoot(root->right, false);
        } else {
            // looting current node
            int loot = root->val + maxLoot(root->left, true) + maxLoot(root->right, true);
            // not looting current node
            int notLoot = maxLoot(root->left, false) + maxLoot(root->right, false);
            
            res = max(loot, notLoot);
        }
        
        // adding to map
        if(isParentLooted) rec[root].first = res;
        else rec[root].second = res;
        return res;
    }
    
    int rob(TreeNode* root) {
        return maxLoot(root, false);
    }
};

// Time Complexity = O(N)
// Space Complexity = O(N) [where N is number of nodes in the tree]
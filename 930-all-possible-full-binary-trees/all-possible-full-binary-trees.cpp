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
    unordered_map<int, vector<TreeNode*>> mp; 
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> result;
                
        if(n % 2 == 0) return {};
        if(n == 1) return {new TreeNode(0)};
        if(mp.find(n) != mp.end()) return mp[n];
        
        
        for(int i = 1; i < n; i += 2){
            auto lst = allPossibleFBT(i);
            auto rst = allPossibleFBT(n - i - 1);
            
            for(auto lnode: lst){
                for(auto rnode: rst){
                    result.push_back(new TreeNode(0, lnode, rnode));
                }
            }
        }
        
        return mp[n] = result;
    }
};
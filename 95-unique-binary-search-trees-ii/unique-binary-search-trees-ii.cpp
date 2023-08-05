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
    vector<TreeNode*> help(int s,int e)
    {
        vector<TreeNode*>v;
        if(s>e) 
        {
            v.push_back(NULL);
            return v;
        }
        for(int i=s;i<=e;i++)
        {
            auto l=help(s,i-1);
            auto r=help(i+1,e);
            for(auto left:l)
            {
                for(auto right:r)
                {
                    TreeNode* newNode=new TreeNode(i,left,right);
                    v.push_back(newNode);
                }
            }
        }
        return v;
    }
    
    vector<TreeNode*>generateTrees(int n) 
    {
        if(n == 0) 
            return vector<TreeNode*>();
        auto ans=help(1,n);
        return ans;
    }
};
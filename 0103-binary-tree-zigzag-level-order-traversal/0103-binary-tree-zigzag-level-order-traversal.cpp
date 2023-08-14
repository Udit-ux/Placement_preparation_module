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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>> ans;
        if(!root){return ans;}
        queue<TreeNode *> q;
        q.push(root);
        int flag = 1;
        while(!q.empty()){
            int s = q.size();
            vector<int> inter;
            for(int i=0;i<s;++i){
                TreeNode * temp = q.front();
                q.pop();
                inter.push_back(temp->val);
                if(temp->left){q.push(temp->left);}
                if(temp->right){q.push(temp->right);}
            }
            if(flag==0){
                reverse(inter.begin(),inter.end());
            }
            ans.push_back(inter);
            flag = 1 - flag;
        }
        return ans;
    }
};
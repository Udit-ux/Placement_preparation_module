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
    TreeNode*f(vector<int>& p, vector<int>& i, int& id, int l, int r) {
          if(l>r)
            return NULL;
        int pt=l;
        while(i[pt]!=p[id])
            pt++;
        id++;
        TreeNode* t=new TreeNode(i[pt]);
        t->left=f(p,i,id,l,pt-1);
        t->right=f(p,i,id,pt+1,r);
        return t;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int id=0;
        return f(preorder,inorder, id, 0, inorder.size()-1);
    }
};
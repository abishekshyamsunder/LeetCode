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
    bool isSubtreeImm(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL && subRoot == NULL)
            return true;
        else if(root==NULL && subRoot !=NULL)
            return false;
        else if(root!=NULL && subRoot == NULL)
            return false;
        if(root->val != subRoot->val)
            return false;
        bool l=true, r=true;
        l = isSubtreeImm(root->left,subRoot->left);
        r = isSubtreeImm(root->right,subRoot->right);
        if(l && r)
            return true;
        return false;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL and subRoot == NULL)
            return true;
        else if(root==NULL and subRoot !=NULL)
            return false;
        else if(root!=NULL and subRoot == NULL)
            return false;
        bool l=true, r=true, tl=true, tr=true;
        if(root->val == subRoot->val)
        {
            // cout<<"Here";
            l = isSubtreeImm(root->left, subRoot->left);
            r = isSubtreeImm(root->right, subRoot->right);
            if(l && r)
                return true;
        }
        
        tl = isSubtree(root->left, subRoot);
        tr = isSubtree(root->right, subRoot);
        if(tl || tr)
            return true;
        
        return false;
        
    }
};

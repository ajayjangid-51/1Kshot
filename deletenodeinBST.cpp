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
  TreeNode* r = curr->left;
        while(r and r->right){
            r = r->right;
        }
        if(r)
        r->right = curr->right;
        if(p){
        p->left = curr->left;
        p->right = NULL;
        }
        if(!p){
            return curr->left;
        }

        return root;
 */
class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        // first get the node:-
        TreeNode *curr = root, *p = NULL;
        while (curr and curr->val != key)
        {
            p = curr;
            if (key < curr->val)
                curr = curr->left;
            else
                curr = curr->right;
        }
        if (!curr)
            return root;
        // now first get the rightmost guy of the curr->left;
        if (!curr->left)
        {
            curr->left = curr->right;
            curr->right = NULL;
        }

        //
        TreeNode *r = curr->left;
        while (r and r->right)
            r = r->right;
        if (r)
        {
            r->right = curr->right;
            curr->right = NULL;
        }
        if (!p)
            return root->left;
        // p->left = curr->left;
        // if(p){
        if (p->left and p->left->val == key)
        {

            p->left = curr->left;
        }
        else
        {

            p->right = curr->left;
        }
        // }
        // else{
        //     // if(root->left)
        //     root= root->left;
        //     // else root = root->right;
        // }
        return root;
    }
};
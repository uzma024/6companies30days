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
    //vector = sum , n
    vector <int> helper(int &ans,TreeNode* root){
        if(root==NULL)return{0,0};
        vector <int> v1=helper(ans,root->left);
        vector <int> v2=helper(ans,root->right);
        int a=v1[0]+v2[0]+root->val;
        int b=v1[1]+v2[1]+1;
        if(b!=0 && a/b==root->val){
            cout<<root->val<<endl;
            ans++;
        }
        return {a,b};
    }

    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        helper(ans,root);
        return ans;
    }
};
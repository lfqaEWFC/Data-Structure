/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int i=0;
int Treeprev(struct TreeNode *root,int* arr){
    
    if(root == NULL){
        return 0;
    }

    arr[i++] = root->val;
    Treeprev(root->left,arr);
    Treeprev(root->right,arr);

    return i;

}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    
    int *arr = (int*)malloc(sizeof(int)*100);
    *returnSize = Treeprev(root,arr);
    i=0;
    return arr;  

}

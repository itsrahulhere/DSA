//Problem: https://practice.geeksforgeeks.org/problems/symmetric-tree/1#

bool iss(Node* r1, Node* r2)
{
    if(!r1 || !r2) return r1==r2;
    
    return (r1->data == r2->data && iss(r1->left, r2->right) && iss(r1->right, r2->left));
}

bool isSymmetric(struct Node* root)
{
    // Code here
    if(!root) return true;

    return iss(root->left, root->right);
}
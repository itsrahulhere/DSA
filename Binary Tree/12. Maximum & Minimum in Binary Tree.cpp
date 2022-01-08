// Problem : https://practice.geeksforgeeks.org/problems/max-and-min-element-in-binary-tree/1/

class Solution
{
public:
    int mx=INT_MIN, mn=INT_MAX;
    
    void calculate(Node *root)
    {
        if(!root)return;
        mx=max(mx,root->data);
        mn=min(mn,root->data);
        calculate(root->left);
        calculate(root->right);
    }
    
    int findMax(Node *root)
    {
        //code here
        calculate(root);
        return mx;
    }
    int findMin(Node *root)
    {
        //code here
        calculate(root);
        return mn;
    }
};
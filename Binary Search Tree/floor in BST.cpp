// Problem Link: https://www.codingninjas.com/codestudio/problems/floor-from-bst_920457

int floorInBST(TreeNode<int> * root, int x)
{
    int floor = -1;
    
    while(root)
    {
    	if(x>=root->val)
            floor=max(floor,root->val);
        if(x < (root->val))
            root=root->left;
        else
            root=root->right;
    }
    
    return floor;
    
}
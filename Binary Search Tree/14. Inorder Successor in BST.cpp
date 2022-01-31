//Problem: https://practice.geeksforgeeks.org/problems/inorder-successor-in-bst/1/

    Node * inOrderSuccessor(Node *root, Node *x)
    {
        //Your code here
        Node* res=NULL;
        
        while(root)
        {
            if(x->data < root->data)
            {
                res=root;
                root=root->left;
            }
            else
                root=root->right;
        }
        
        return res;
    }
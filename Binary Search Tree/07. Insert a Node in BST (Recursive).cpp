//Problem: https://practice.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1

Node* insert(Node* root, int Key) {
    if(!root){
        Node*root=new Node(Key);
        return root;
    }
    
    if(Key < root->data)
        root->left = insert(root->left, Key);

    else if(Key > root->data)
        root->right = insert(root->right, Key);
    
    return root;
}
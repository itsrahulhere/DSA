// Problem: https://practice.geeksforgeeks.org/problems/level-order-traversal/1

    vector<int> levelOrder(Node* node)
    {
      //Your code here
      vector<int> v;
      if(node==NULL)return v;
      
      queue<Node*>q;
      q.push(node);
      
      while(q.empty()==NULL)
      {
          int size=q.size();
          for(int i=0; i<size;i++)
          {
              Node* curr=q.front();
              q.pop();
              v.push_back(curr->data);

              if(curr->left) q.push(curr->left);
              if(curr->right) q.push(curr->right);
          }
      }
      
      return v;
    }
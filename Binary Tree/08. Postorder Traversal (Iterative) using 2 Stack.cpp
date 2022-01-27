//Problem: https://practice.geeksforgeeks.org/problems/postorder-traversal-iterative/0/

    vector<int> postOrder(Node* node) 
    {    
        vector<int> ans;
        if(!node) return ans;
        stack<Node*> st1, st2;
        st1.push(node);
        while(!st1.empty())
        {
            Node* curr=st1.top();
            st1.pop();
            st2.push(curr);
            if(curr->left) st1.push(curr->left);
            if(curr->right) st1.push(curr->right);
            
        }
        while(!st2.empty())
        {
            ans.push_back(st2.top()->data);
            st2.pop();
        }
        return ans;
    }

//reversing the vector
vector <int> postOrder(Node* root)
{
  // Your code here
  vector<int> ans;
  
  stack<Node*> s1;
  s1.push(root);
  
  while(!s1.empty())
  {
      Node* curr=s1.top();
      s1.pop();
      
      ans.push_back(curr->data);
      
      if(curr->left)s1.push(curr->left);
      if(curr->right)s1.push(curr->right);
      
  }
  
  reverse(ans.begin(),ans.end());
  return ans;
}
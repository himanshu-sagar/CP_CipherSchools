Node* connect(Node* root) {
        if(root==NULL) return root;
        queue<Node*> q;
        Node* temp = root;
        q.push(temp);
        while(!q.empty()){
            int n = q.size();
            Node* curr = NULL;
            Node* t = NULL;
            for(int i=0;i<n;i++){
                curr = q.front();
                q.pop();
                if(t){
                    if(curr->left) t->next = curr->left;
                    else if(curr->right) t->next = curr->right;
                    else t->next = NULL;
                }
                if(curr->left && curr->right) curr->left->next = curr->right;
                if(curr->left) q.push(curr->left);
                if(curr->right){
                    q.push(curr->right);
                    t = curr->right;
                }
            }
            curr->next = NULL;
        }
        return root;
    }
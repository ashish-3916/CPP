 vector<int> inorderTraversal(TreeNode* root) {
        // left root right 
        vector<int> res ;
        TreeNode* curr = root;
        while(curr)
        {
            if(curr->left)
            {
                TreeNode* temp = curr->left;
                while(temp->right !=NULL and temp-> right != curr ) // move to rightmost 
                    temp=temp->right;
                
                if(temp->right==NULL)
                { temp->right = curr; curr=curr->left;} // make a link 
                else if( temp-> right == curr)
                {
                    temp-> right= NULL; // remove the link 
                    res.push_back(curr->val);
                    curr= curr-> right;
                }
                    
            }
            else
            {
                res.push_back(curr->val);
                curr=curr->right;
            }
        }
        return res;
    }


vector<int> preorderTraversal(TreeNode* root) {
        // node left right
        TreeNode* curr = root; 
        vector<int> res; 
        
        while(curr)
        {
            if(curr->left)
            {
                TreeNode* temp = curr->left;
                while(temp->right !=NULL and temp-> right != curr ) // move to rightmost 
                    temp=temp->right;
                
                if(temp->right==NULL)
                {   temp->right = curr; // make a link 
                    res.push_back(curr->val);
                    curr=curr->left;
                } 
               
                else if( temp-> right == curr)
                {
                    temp-> right= NULL; // remove the link 
                    curr= curr-> right; // also curr is already visited , so we don't push it again
                }
                    
            }
            else
            {
                res.push_back(curr->val);
                curr=curr->right;
            }
        }
        return res ;
    }

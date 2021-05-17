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

  vector<int> postorderTraversal(TreeNode* root)
    {

// Making our tree left subtree of a dummy TreeNode
        TreeNode *dummyRoot = new TreeNode(0);
        dummyRoot->left = root;
        vector<int> res;
//Think of P as the current TreeNode
        TreeNode *p = dummyRoot, *pred, *first, *middle, *last;
        while (p != NULL) {

            if (p->left == NULL) {
                p = p->right;
            } else {
                /* p has a left child => it also has a predeccessor
                   make p as right child predeccessor of p
                */
                pred = p->left;
                while (pred->right != NULL && pred->right != p) {
                    pred = pred->right;
                }

                if (pred->right == NULL) {

                    // predeccessor found for first time
                    // modify the tree

                    pred->right = p;
                    p = p->left;

                } else {

                    // predeccessor found second time
                    // reverse the right references in chain from pred to p
                    first = p;
                    middle = p->left;
                    while (middle != p) {
                        last = middle->right;
                        middle->right = first;
                        first = middle;
                        middle = last;
                    }

                    // visit the nodes from pred to p
                    // again reverse the right references from pred to p
                    first = p;
                    middle = pred;
                    while (middle != p) {

                        res.push_back(middle->val);
                        last = middle->right;
                        middle->right = first;
                        first = middle;
                        middle = last;
                    }

                    // remove the pred to TreeNode reference to restore the tree structure
                    pred->right = NULL;
                    p = p-> right;
                }
            }

        }
        return res;
    }

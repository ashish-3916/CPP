vector<int> inorderTraversal(TreeNode* root) {
       // left node right
        stack<pair<TreeNode*, int>>s;
        vector<int> ans ;
        s.push({root, 0});
        
        while(s.size())
        {
            auto  t = s.top();
            TreeNode* node = t.first;
            int lvl = t.second;          
            s.pop();
            if(lvl== 3 or node ==NULL) continue;
            s.push({node , lvl+1});
            
            if(lvl==0)s.push({node->left,0});
            else if(lvl == 1) ans.push_back(node->val);
            else if(lvl==2)s.push({node->right, 0});
        
        }
        return ans;
    }


vector<int> preorderTraversal(TreeNode* root) {
        // node left right
        stack<pair<TreeNode*, int>>s;
        vector<int> ans ;
        s.push({root, 0});
        
        while(s.size())
        {
            auto  t = s.top();
            TreeNode* node = t.first;
            int lvl = t.second;          
            s.pop();
            if(lvl== 3 or node ==NULL) continue;
            s.push({node , lvl+1});
            
            if(lvl==1)s.push({node->left,0});
            else if(lvl == 0) ans.push_back(node->val);
            else if(lvl==2)s.push({node->right, 0});
        
        }
        return ans;
    }

vector<int> postorderTraversal(TreeNode* root) {
        // left right node
        stack<pair<TreeNode*, int>>s;
        vector<int> ans ;
        s.push({root, 0});
        
        while(s.size())
        {
            auto  t = s.top();
            TreeNode* node = t.first;
            int lvl = t.second;          
            s.pop();
            if(lvl== 3 or node ==NULL) continue;
            s.push({node , lvl+1});
            
            if(lvl==0)s.push({node->left,0});
            else if(lvl == 2) ans.push_back(node->val);
            else if(lvl==1)s.push({node->right, 0});
        
        }
        return ans;
    }

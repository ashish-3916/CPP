class NumArray {
    
    vector<int> st;
                     // 1 based index array
    int n;//size
    
   void build_tree(vector<int>&arr, vector<int> &st, int si , int ss , int se)
   {
       if(ss==se)
       {
           st[si]=arr[ss];return;
           
       }
       int mid = ss + (se-ss)/2;
       build_tree( arr, st , 2*si , ss , mid );
       build_tree (arr , st , 2*si+1 , mid+1 , se);
           
         st[si]= st[2*si]+st[2*si+1];
       
   }
    void update_st (  vector<int> &st , int si , int ss, int se , int qi , int val)
    {
        if(ss == se )
        {
            st[si]=val;return ;
        }
        int mid = ss +(se-ss)/2;
        if(mid>= qi )
            update_st(st, 2*si , ss , mid , qi , val);
        else
            update_st(st , 2*si+1 , mid+1 , se  , qi , val );
        
        st[si] = st[2*si]+ st[2*si+1];
    }
    
    int sum_st( vector<int> &st , int si , int ss , int se , int l , int r )
    { // completely outside
        if (se < l || ss > r)       // se  l r ss
        return 0 ; // sum
    // totally overlapping
         if (ss >= l && r >= se) //    l ss se r
            { return st[si]; }

    int mid = ss + (se - ss) / 2 ;

    int L = sum_st (st,2 * si , ss , mid , l, r);
    int R = sum_st (st, 2 * si + 1 , mid + 1 , se , l, r);

    return L + R;
    }
    
    
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        if(n==0)return;
        auto it = nums.insert(nums.begin(),0);// making 1 base indexing
                
   // int height = (int)(ceil(log2(n+1)));   

     //  int st_size = 2*(int)pow(2, height);  
       st.resize(4*n+4,0);
        
        build_tree(nums,st, 1,1,n);
        
    }
    
    void update(int i, int val) {
        //arr[i+1] = val;
        update_st(st, 1 , 1, n ,i+1 , val);
    }
    
    int sumRange(int i, int j) {
        return sum_st(st, 1,1,n,i+1,j+1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */

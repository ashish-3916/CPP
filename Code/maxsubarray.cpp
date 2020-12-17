int maxSubArray(vector<int>& nums) {
        int final=nums[0];
        int curr = nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            if(curr+ nums[i] >nums[i])
            {
                curr+=nums[i];
            }
            else
            {
                curr=nums[i];
            }
            
            if(final < curr)
                final= curr;

        }
        
        return final;
    }

// to be done via segment tree for range of queries

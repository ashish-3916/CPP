/*
to count the no of set bits in  a #n we follow 

while(n>0 )
{
  cnt++;
  n = n & (n-1);
}

now this can be written in a recursive manner 

if(n==0)
return 0;

return 1 + f(n&(n-1);


so f(n)= 1 + f(n&(n-1)

which leads us to the solution to find in given range to do in O(N)

*/

  vector<int> countBits(int num) {
        vector<int>ans;
        ans.push_back(0);
        
        for(int i=1 ; i<= num ; i++)
        {
            ans.push_back(1+ ans[i &(i-1)]);
        }
        
        return ans;
    }
    
    
    // other solution 
    /* its to find for n/2 ie right shift of the no and check MSB of current no
    */
    
     vector<int> countBits(int num) {
        vector<int> v(num+1,0);

        for(int i=1;i<= num; i++) v[i]=v[i/2]+i%2;

        return v;
    }

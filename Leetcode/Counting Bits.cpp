/*Solution 1 :
To count the # of set bits in a given n we follow :
*/
int cnt=0;
while(n>0 )
{
  cnt++;
  n = n & (n-1);
}
return cnt;

//now this can be written in a recursive manner :

void f(n)
{
	if(n==0)
		return 0;
	return 1 + f(n&(n-1);
}
               /*
The recurrence relation is :
f(n)= 1 + f( n&(n-1) )

which gives us the intuition of DP solution

which leads us to the solution to find # of set bits in given range to do in O(N)*/

  vector<int> countBits(int num) {
        vector<int>ans;
        ans.push_back(0);
        
        for(int i=1 ; i<= num ; i++)
        {
            ans.push_back(1+ ans[i &(i-1)]);
        }
        
        return ans;
    }
               /*
Solution 2:
total # of set bits is n can be seen as set bits is n/2 ( right shift ) and checking LSB
Example for n = 5
1 0 1 <-- 5
0 1 0 <-- (5/2=2 ie n>>1)

so 2 contains 1 set bit and also we check for LSB of 5 , so 5 is odd , so 1 bit from there
so total of 2 set bits in 5.

relation can be written as

f(n) = f(n/2) + n%2

code:*/

 vector<int> countBits(int num) {
	vector<int> v(num+1,0);

	for(int i=1;i<= num; i++) v[i]=v[i/2]+i%2;

	return v;
}

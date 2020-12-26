// DP  O(N)
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        for (int i = 1 ; i < arr.size(); i++)
        {
            arr[i] = arr[i] ^ arr[i - 1];
        }

        for (int i = 0 ; i < queries.size(); i++)
        {
            int l = queries[i][0];
            int r = queries[i][1];
            if (l == 0 && r == 0)
                ans.push_back(arr[l);
            else if (l != 0 && r != 0)
                ans.push_back(arr[r]^arr[l - 1]);
            else
              ans.push_back(arr[r]);

            }
        return ans;
    }
};


// segment tree O(  q * log n )
 

class Solution {
public:

void build_tree(vector<int>& arr,vector<int>& st , int si , int ss , int se)
{
    if(ss==se)
    {
        st[si]=arr[ss]; 
        return ;
    }
        int mid = ss +(se-ss)/2;
        build_tree(arr,st,2*si, ss, mid);
        build_tree(arr,st,2*si+1 ,mid+1 ,se);
        st[si]= st[2*si] ^ st[2*si+1];
}
int query (vector<int> & st , int si , int ss , int se , int qs , int qe )
{
    // completely outside
    if(qe<ss ||  se<qs) // qe-ss , se-qs
        return 0;
    //completely inside
    if(qs<=ss && se<=qe)//qs <=ss<= se<= qe
        return st[si];
   int mid = ss +(se-ss)/2;
    int l= query(st, 2*si ,ss , mid, qs,qe);
    int r=query(st , 2*si+1 , mid+1 , se , qs ,qe);
    return l^r;
}


vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {

    
    int n = arr.size();
    auto it =  arr.insert(arr.begin(), 0); // 1 based indexing
    vector<int> st(4 * n, 0);

    vector<int > ans;
    build_tree(arr, st, 1, 1, n);
    for(int i=0 ;i< queries.size();i++)
    {
        int l = queries[i][0];
        int r = queries[i][1];

        ans.push_back( query(st, 1,1,n ,l+1,r+1) );
    }
    return ans;

}
};

#include <iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;


void buildTree(int seg[],int arr[], int si, int ss, int se) //building minimum seg tree
{
    if(ss==se)
    {
        seg[si]=arr[ss];
        return;
    }
    int mid =(ss+se)/2;
    buildTree(seg,arr,2*si,ss, mid);
    buildTree(seg,arr,2*si+1,mid+1,se);

    seg[si]=min(seg[2*si],seg[2*si+1]);
}

int query(int seg[],int si, int ss , int se, int qs,int qe) // obv ss<=qs<=qe<=se
{
    if(qe < ss || qs >se) //completly outside
        return INT_MAX;
    if (ss >=qs && se <=qe) //complety inside        qs   ss------se   qe 
    {
        return seg[si];
    }
    int mid= (ss+se)/2;
    int l=query(seg,2*si , ss,mid,qs,qe);
    int r=query(seg,2*si+1,mid+1,se,qs,qe);
    return min(l,r);
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n ; 
    cin>>n;//7
    
    int arr[n+1];
    arr[0]=0;
   for(int i=1;i<=n;i++)
    {
        cin>>arr[i];// 1 5 9 -1 5 -3 8 
    }
    int size=4*(n+1);
    int seg[size];
    memset(seg,0,sizeof(seg));
   buildTree(seg,arr,1,1,n);// build segtree from starting index in range L to R ; 
   

   int t;
   cin>>t; //4
   while (t--)
   {
    int x,y;
    cin>>x>>y;
    int ans=query(seg,1,1,n,x+1,y+1);/// seg[],si,L,R,l,r;
    cout<<ans<<endl;//answer ismaximium no in l,r

   }
    return 0;
}

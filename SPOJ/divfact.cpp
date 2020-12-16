#include <iostream>
#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007 
using namespace std;

vector<bool> check(50001,true);
vector<int> prime;

void sieve()
{
    for(int i = 2 ; i*i <= 50000 ; i++)
    {
        if(check[i])
        {
            //prime.push_back(i);
            for(int j = i*i ; j <= 50000; j+=i)
                check[j]=false;
        }
    }
    for(int i=2; i<=50000 ;i++)
        {
            if(check[i]) prime.push_back(i);
        }
    
}

void divfact()
{
    int n;
    cin>>n;
   
    ll res=1;
    for(int i=0 ; prime[i]<=n ; i++)
    {
        int curr=prime[i];
        int ans=0;
        while(n/curr !=0)
        {
            int small = n/curr;
            ans=ans+small;

            curr*=prime[i];
        }
        ans++;
        res = (res*ans)%MOD;
    }
    cout<<res<<endl;

}
int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    sieve();
    int t;cin>>t;
    while(t--)
    {
        divfact();
    }


 
}

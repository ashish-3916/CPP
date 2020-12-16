#include <iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<bool> check(32000,true);//sqrt(10^9)
vector<int> prime;

void sieve()
{
    for(int i = 2 ; i*i <= 32000 ; i++)
    {
        if(check[i])
        {
            //prime.push_back(i);
            for(int j = i*i ; j <= 32000; j+=i)
                check[j]=false;
        }
    }
    for(int i=2; i<=32000 ;i++)
        {
            if(check[i]) prime.push_back(i);
        }
    
}
void seg_sieve()
{
    ll l,h;
    cin>>l>>h;

    ll low,high;
    low=(l<h)?l:h;
    high=(l>h)?l:h;
    //cout<< low<<" "<<high;
    if(low==1)low++;

    vector<bool> isprime(high-low+1, true);

    for(int i=0;prime[i]*prime[i]<=high;i++)
    {  
        
        int p= prime[i];

        int nearest_multiple= (low/p)*p;
        if(nearest_multiple < low)
            nearest_multiple+=p;

        for(ll j = nearest_multiple ; j<=high ; j+=p)
        { if(j!=prime[i])
             isprime[j-low]=false;
        }
    }

    for(ll i = 0; i<isprime.size(); i++)
    {
        if(isprime[i]) cout<< i+low <<" ";
    }
    cout<<endl;
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
       seg_sieve();
    }


 
}

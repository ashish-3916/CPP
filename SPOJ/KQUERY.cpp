
#include <iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;



ll arr[30001];
vector<ll> st[120004];

void build_tree(int si , int ss , int se)     // merge sort tree
{
    if (ss == se)
    {
        st[si].push_back(arr[ss]); return;
    }
    int mid = ss + (se - ss) / 2;
    build_tree(2 * si, ss, mid);
    build_tree(2 * si + 1 , mid + 1 , se);

  //  vector<ll>L = st[2 * si];      dont do this , it will result TLE are we 
  //  vector<ll>R = st[2 * si + 1];  are assigninf and it take additional O(N)

    // see your own previous submission on codeforces / SPOJ

    int i = 0, j = 0;

    while (i <  st[2 * si].size() && j < st[2 * si + 1].size())
    {
        if ( st[2 * si][i] <= st[2 * si + 1][j])
            st[si].push_back( st[2 * si][i]), i++;
        else
            st[si].push_back(st[2 * si + 1][j]), j++;

    }
   
        while (i < st[2 * si].size())
            st[si].push_back(st[2 * si][i]), i++;
    
    
        while (j < st[2 * si + 1].size())
            st[si].push_back(st[2 * si + 1][j]), j++;
    


}

ll query(ll si , ll ss , ll se , ll qs , ll qe , ll k ) // > k
{
    // completely outside  qe ss se qs
    if (qe < ss || se < qs)
        return 0;
    //compleetely inside   qs ss se qe
    if (qs <= ss && se <= qe)
    {   // we find elements greater than k
       // vector<ll> node = st[si];
        int no =  st[si].end() - upper_bound(st[si].begin(), st[si].end(), k);
        return no;

    }
    ll mid = ss + (se - ss) / 2;
    ll L = query(2 * si , ss , mid , qs , qe , k);
    ll R = query(2 * si + 1, mid + 1, se, qs, qe, k);

    return L + R;


}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> arr[i];

    build_tree(1, 1, n);
    int q;
    cin >> q;
    while (q--)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        cout << query(1, 1, n, x, y, z) << endl;
    }


    return 0;
}

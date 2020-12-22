/*
You are given a sequence A[1], A[2], ..., A[N] . ( |A[i]| ≤ 15007 , 1 ≤ N ≤ 50000 ). A query is defined as follows:
Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x ≤ i ≤ j ≤ y }.
Given M queries, your program must output the results of these queries.


constraints are important , check query base condition
*/

#include <iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;





class node {
public:
    int sum;
    int suffix;
    int prefix;
    int ans;
};


void build_tree(int arr[] , node st[] , int si , int ss, int se)
{
    if (ss > se)
        return;
    if (ss == se)
    {
        node p ;
        p.sum = p.suffix = p.prefix = p.ans = arr[ss];
        st[si] = p;
        return;
    }

    int mid = ss + (se - ss) / 2;
    build_tree(arr, st, si * 2 , ss , mid);
    build_tree(arr, st , 2 * si + 1 , mid + 1 , se);

    node l = st[2 * si];
    node r = st[2 * si + 1];
    node res;
    res.sum = l.sum + r.sum;
    res.prefix = max(l.prefix , l.sum + r.prefix);
    res.suffix = max(r.suffix, r.sum + l.suffix);
    res.ans = max(max(l.ans, r.ans), l.suffix + r.prefix);
    st[si] = res;

}
node  query(node st[], int si , int ss, int se , int qs, int qe) // ss l r se
{
    if (ss > se || ss > qe || se < qs)
    {
        node res ;
        res.sum = res.suffix = res.prefix = res.ans = -15008;
        return res;

    }

    if (ss >= qs && qe >= se)
        return st[si];

    int mid = ss + (se - ss) / 2;
    node l = query(st, si * 2, ss, mid , qs , qe );
    node r = query(st, 2 * si + 1, mid + 1 , se , qs,  qe );
    node res;
    res.sum = l.sum + r.sum;
    res.prefix = max(l.prefix , l.sum + r.prefix);
    res.suffix = max(r.suffix, r.sum + l.suffix);
    res.ans = max(max(l.ans, r.ans), l.suffix + r.prefix);
    return res;

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
    int arr[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    node st[4 * n + 4];
    memset(st, 0, sizeof(st));

    build_tree(arr, st , 1 , 1, n);
    /*for (int i = 0; i <= 4 * n + 4 ; i++)
    {   cout << st[i].sum << " " << st[i].prefix << " " << st[i].suffix << " " << st[i].ans << endl;
    }*/
   // cout << endl;
    int t; cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        cout << query(st, 1, 1 , n, l , r).ans << endl;
    }

    return 0;
}

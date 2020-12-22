/*
query -> 1 L R
update -> 0 L R value

10  size of array
5   test cases
1 1 10   
0 1 1 10
1 1 10
0 2 10 10
1 1 10
*/

#include<bits/stdc++.h>
using namespace std;
const int maxN = 100001;
int ar[maxN];
int st[4 * maxN] , lazy[4 * maxN];

void build(int si , int ss , int se)//building segment tree ,, not much need as in this code
{   // there is no cin>> and globally arrray are initilized by 0;
    if (ss == se)
    {
        st[si] = ar[ss];
        return;
    }

    int mid = (ss + se) / 2;

    build(2 * si , ss , mid);
    build(2 * si + 1 , mid + 1 , se);

    st[si] = st[2 * si] + st[2 * si + 1];
}

int query(int si , int ss , int se , int qs , int qe)//note -> value stored by lazy node
{
    if (lazy[si] != 0) // check in lazy notebook
    {
        int dx = lazy[si]; /// save the note
        lazy[si] = 0; // set current note to 0
        st[si] += dx * (se - ss + 1); // update seg node  with (note * no of elements) in the range

        if (ss != se)
            lazy[2 * si] += dx , lazy[2 * si + 1] += dx; // pass the note to children
    }

    // normal process
    if (ss > qe || se < qs) //completly outside
        return 0;

    if (ss >= qs && se <= qe) // overlapping
        return st[si];

    int mid = (ss + se) / 2;
    return query(2 * si , ss , mid , qs , qe) + query(2 * si + 1 , mid + 1 , se , qs , qe);
}

void update(int si , int ss , int se , int qs , int qe , int val)
{
    if (lazy[si] != 0) // check if initial updates are to be done or not
    {
        int dx = lazy[si];
        lazy[si] = 0;
        st[si] += dx * (se - ss + 1);

        if (ss != se)
            lazy[2 * si] += dx , lazy[2 * si + 1] += dx;
    }

    if (ss > qe || se < qs) return;

    // now if the segment is overlapping we update the segment of that range
    // and pass the lazy update to the childrens if present

    if (ss >= qs && se <= qe) // qs ss se qe
    {
        int dx = (se - ss + 1) * val;
        st[si] += dx;

        if (ss != se)
            lazy[2 * si] += val , lazy[2 * si + 1] += val;
        return;
    }

    int mid = (ss + se) / 2;
    update(2 * si , ss , mid , qs , qe , val);
    update(2 * si + 1 , mid + 1 , se , qs , qe , val);

    st[si] = st[2 * si] + st[2 * si + 1];
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n , t , code , l , r , val;
    cin >> n >> t;
    build(1 , 1 , n);

    while (t--)
    {
        cin >> code;
        if (code == 1)
        {
            cin >> l >> r;
            cout << query(1 , 1 , n , l , r) << endl;
        }
        else
        {
            cin >> l >> r >> val;
            update(1 , 1 , n , l , r , val);
        }
    }
}

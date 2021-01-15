//https://codeforces.com/contest/1473/problem/C

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define F first
#define S second
#define setbit(n) __builtin_popcount(n)
#define all(x) x.begin() , x.end()
#define clr(x) memset(x,0,sizeof(x))
#define endl "\n" //delete if interactive
using namespace std;

int query (int st[] , int si , int ss , int se, int l, int r)
{
	if (se < l || ss > r)       // se  l r ss
		return 0 ; // sum
	// totally overlapping
	if (ss >= l && r >= se) //    l ss se r
	{ return st[si]; }

	int mid = ss + (se - ss) / 2 ;

	int L = query (st, 2 * si  , ss , mid , l, r);
	int R = query (st, 2 * si + 1 , mid + 1 , se , l, r);

	return L + R;
}
void build_tree(int sign[] , int st[] , int si, int ss , int se)
{
	if (ss == se)
	{st[si] = sign[ss]; return;}

	int mid = (ss + se ) / 2;
	build_tree(sign , st , 2 * si , ss, mid);
	build_tree(sign , st , 2 * si + 1, mid + 1, se);

	st[si] = st[2 * si ] + st[2 * si + 1];

}
void solve()
{
	int n , m;
	cin >> n >> m;
	string s;
	cin >> s;
	int sign[n + 1];
	for (int i = 0 ; i < n ; i++)
	{
		if (s[i] == '+')sign[i + 1] = 1; else sign[i + 1] = -1;
	}

	int dp[n + 1] , st[4 * n + 4];
	dp[1] = sign[1];
	for (int i = 2; i <= n ; i++)
		dp[i] = dp[i - 1] + sign[i];

	vector< array < int , 2> > fro (n + 1), bck(n + 1);

	int mini_fro = dp[1], maxi_fro = dp[1];
	fro[1][0] = maxi_fro;
	fro[1][1] = mini_fro;
	for (int i = 2 ; i <= n ; i++)
	{
		if (dp[i] > maxi_fro) maxi_fro = dp[i];
		if (dp[i] < mini_fro) mini_fro = dp[i];

		fro[i][0] = maxi_fro;
		fro[i][1] = mini_fro;
	}
	//cout << dp[8];
	int mini_bck = dp[n], maxi_bck = dp[n];
	bck[n][0] = maxi_bck;
	bck[n][1] = mini_bck;
	for (int i = n - 1 ; i >= 1 ; i--)
	{
		if (dp[i] > maxi_bck) maxi_bck = dp[i];
		if (dp[i] < mini_bck) mini_bck = dp[i];

		bck[i][0] = maxi_bck;
		bck[i][1] = mini_bck;
	}

	build_tree(sign, st, 1, 1, n );
	//for (int i = 0 ; i < 4 * n; i++)cout << st[i] << endl;
	while (m--)
	{
		int l , r;
		cin >> l >> r;
		int ans = query( st, 1 , 1, n  , l, r);
		//cout << ans << endl;
		int Min = 0, Max = 0;

		if (l > 1)
		{
			array<int , 2> p = fro[l - 1];
			Min = p[1];
			Max = p[0];
		}

		int x = 0, y = 0;
		if (r < n)
		{	if (r + 1 == n)
			{
				x = y = dp[r + 1] - ans;
			}
			else {
				array<int , 2> p = bck[r + 1];
				//cout << p[0] << p[1] << endl;
				x = p[0] - ans; //max
				y = p[1] - ans; //min
			}
		}
		//cout << Max << " " << Min << " " << x << " " << y << endl;
		int q = max(Max, x), w = min(Min, y ) ;
		if (q < 0 || w > 0)
			cout << q - w + 2 << endl;
		else
			cout << q - w + 1 << endl;

	}
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--)
	{solve();}
	return 0;
}


//https://www.codechef.com/JAN21B/problems/ANTSCHEF

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
// #define int long long // delete if it causes problem
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define F first
#define S second
#define setbit(n) __builtin_popcount(n)
#define all(x) x.begin() , x.end()
#define clr(x) memset(x,0,sizeof(x))
#define endl "\n" //delete if interactive
using namespace std;

class point {
public:
	int sign ; //-1 neg and 1 for positive
	int line_no; // ith line it belongs to
	int value;  // its abs magnitude

	point(int x, int y, int z)
	{
		sign = x;
		line_no = y;
		value = z;
	}
};
struct myfunc {
	bool operator()(const point &p1 , const point &p2 )
	{
		return p1.value > p2.value;
	}
};

void solve()
{
	int n; cin >> n;
	unordered_map<int, int>distance; // abs(distance) from origin
	vector<vector<int> >  lines(n); 
	vector< array<int , 2> > coordinates(n); // count of positive and negative coordinates in that ith line

	priority_queue <point , vector<point>, myfunc> pq;
	ll ans = 0;
	for (int i = 0; i < n ; i++)
	{
		int m;
		cin >> m;
		for (int j = 0 ; j < m; j++)
		{
			int x; cin >> x ;
			if (x > 0) {
				pq.push(point(1, i, abs(x)));
				coordinates[i][0]++; }//positive coordinates
			else {
				pq.push(point(-1, i, abs(x)));
				 coordinates[i][1]++;}// negative coordinate

			lines[i].push_back(x);

			if (distance[abs(x)] == 1) ans++; // considering collision at origin

			distance[abs(x)]++; // mapping
		}
		//sort(all(lines[i]));
	}
	//cout << ans << " " << coordinates[0][0] << " " << coordinates[0][1] << endl;
	while (!pq.empty())
	{
		point top = pq.top();
		pq.pop();

		if (distance[top.value] > 1) // if already collided on origin once soo it has changed direction
		{
			if ( top.sign == -1) //is negative then its has to collide with remainng negs
			{
				coordinates[top.line_no][1]--; // and remove it
				ans += coordinates[top.line_no][1];

			}
			else if ( top.sign == 1)
			{
				coordinates[top.line_no][0]--;
				ans += coordinates[top.line_no][0];
			}
		}
		else
		{
			if ( top.sign == -1) //is negative  ,so will collide with remaing positives
			{
				coordinates[top.line_no][1]--;
				ans += coordinates[top.line_no][0];

			}
			else if ( top.sign == 1)
			{
				coordinates[top.line_no][0]--;
				ans += coordinates[top.line_no][1];
			}
		}
		//cout << ans << " " << coordinates[0][0] << " " << coordinates[0][1] << endl;
	}
	cout << ans << endl;
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


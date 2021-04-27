/*
https://www.spoj.com/problems/PPATH/

SOME GREAT USE OF SIEVE , GRAPH-BFS ALL TOGETHER , CAN'T BELEIVE I DID IT 1 GO AC , WITHOUT ANY HELP!!!!!
*/

#include <bits/stdc++.h>
#define ll long long
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define F first
#define S second
#define setbit(n) __builtin_popcount(n)
#define all(x) x.begin() , x.end()
#define clr(x) memset(x,0,sizeof(x))
#define pb push_back
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define endl "\n" //delete if interactive
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ASHISH_DANGI
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif


const int N = 10000;

vector<int>graph[N];
vector<bool> visited(N);


vector<bool> isprime(N , true);
void sieve()
{	isprime[0] = isprime[1] = false;
	for (int i = 2 ; i * i <= N  ; i++)
	{
		if (isprime[i])
		{
			for (int j = i * i ; j <= N ; j += i)
				isprime[j] = false;
		}
	}
}
void build(int i )
{
	int temp =  i;
	string s = to_string(i);
	string p = s;
//	vector<int > arr { (i % 10000) / 1000, (i % 1000) / 100, (i % 100) / 10, i % 10} ;

	for (int i = 0 ; i < 4 ; i++)
	{
		int j = 0 ;
		int digit = s[i] - '0';
		//debug(digit);
		if (i == 0)j++;
		for ( ; j < 10 ; j++)
		{
			if (j == digit)
				continue;

			s[i] = '0' + j;

			int no = stoi(s);
			//debug(no);
			if (isprime[no])
				graph[temp].push_back(no);
		}
		s = p;
	}


}
void precomp()
{
	sieve();
	for (int i = 1000; i < N ; i++)
	{
		if (isprime[i])
		{
			build(i);
		}
	}
}




int bfs(int sv , int ev)
{
	visited[sv] = 1 ;

	queue<pair<int, int>> q ; //  parent , depth
	q.push({sv, 0});

	while (!q.empty())
	{

		int s  = q.size();

		for (int i = 0 ; i < s ; i++)
		{
			auto f = q.front();

			q.pop();

			for (int child : graph[f.first])
			{
				if (child == ev)
					return f.second + 1;

				if (!visited[child])
					q.push({child , f.second + 1});
			}
		}
	}
	return -1 ;
}
void solve()
{
	int a , b ;
	cin >> a >> b;
	if (a == b)
	{
		cout << 0 << endl;
		return;
	}

	for (int i = 0 ; i < N ; i++)
		visited[i] = false;


	int ans  = bfs(a , b);

	if (ans == -1 )
		cout << "impossible" << endl;
	else
		cout << ans << endl;



}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;

  precomp();

	while (t--)
	{solve();}
	return 0;

}


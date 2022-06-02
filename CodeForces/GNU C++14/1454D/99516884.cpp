#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

void solve() {
	long long int n;
	cin >> n;
	long long int x = n;
	vector<pair<int, long long int> > factorise;
	for(long long int i = 2; i * i <= n; ++i){
		int cnt = 0;
		while(x % i == 0){
			x /= i;
			++cnt;
		}
		factorise.push_back({cnt, i});
	}
	if(x > 1)
		factorise.push_back({1, x});
	sort(factorise.rbegin(), factorise.rend());
	cout << factorise[0].first << '\n';
	for(int i = 1; i < factorise[0].first; ++i)
		cout << factorise[0].second << ' ';
	long long int last = n/(pow(factorise[0].second, factorise[0].first - 1));
	cout << last << '\n';
}

int main() {
	fast;
	int t = 1;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
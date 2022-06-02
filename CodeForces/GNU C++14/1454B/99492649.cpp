#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 72;
const int MOD = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	map<int, int> mp, pos;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		pos[x] = i + 1;
		mp[x]++;
	}
	for(auto k : mp){
		if(k.second == 1){
			cout << pos[k.first] << '\n';
			return;
		}
	}
	cout << "-1\n";
}

int main() {
	fast;
	int t = 1;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
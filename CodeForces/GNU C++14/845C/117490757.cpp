#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

void solve(){
	int n;
	cin >> n;
	pair<int, int> a[n + 1];
	vector<pair<int, int> > seg;
	for(int i = 1; i <= n; ++i){
		cin >> a[i].first >> a[i].second;
		seg.push_back({a[i].first, 1});
		seg.push_back({a[i].second + 1, -1});
	}
	sort(seg.begin(), seg.end());
	int cons = 0;
	for(auto k : seg){
		cons += k.second;
		if(cons >= 3){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main() {
	fast;
	int t = 1;
    // cin >> t;
	while(t--)
		solve();
}
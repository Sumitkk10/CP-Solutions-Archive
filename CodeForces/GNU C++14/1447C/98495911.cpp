#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	ll n, k;
	cin >> n >> k;
	ll tar = (k + 1) / 2;
	vector<pair<int, int> > a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i].first;
		a[i].second = i + 1;
	}
	long long int sum = 0;
	sort(a.rbegin(), a.rend());
	if(a[n - 1].first > k){
		cout << "-1\n";
		return;
	}
	vector<int> ans;
	for(int i = 0; i < n; ++i){
		if(sum + a[i].first <= k){
			sum += a[i].first;
			ans.push_back(a[i].second);
		}
		if(sum >= tar){
			cout << ans.size() << '\n';
			for(auto k : ans)
				cout << k << ' ';
			cout << '\n';
			return;
		}
	}
	cout << "-1\n";
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	int a[n];
	map<int, int> mp;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		mp[a[i]]++;
	}
	bool ans = 0;
	for(auto k : mp)
		if(k.second > 1)
			ans = 1;
	if(ans) cout << "YES\n";
	else
		cout << "NO\n";
}

int main(){
	fast;
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}

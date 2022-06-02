#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	map<int, int> mp;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		mp[x]++;
	}
	long long ans = 0;
	for(auto k : mp)
		if(k.second >= k.first)
			ans += k.first;
	cout << ans << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
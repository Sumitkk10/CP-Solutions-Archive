#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int n, k;
	cin >> n >> k;
	bool vis[n];
	memset(vis, 0, sizeof vis);
	vector<int> ans;
	for(int i = k + 1; i <= n; ++i)
		ans.push_back(i);
	for(int i = k - 1; i >= 1; --i){
		if(vis[i]) continue;
		vis[k - i] = true;
		ans.push_back(i);
	}
	cout << ans.size() << "\n";
	for(auto k : ans)
		cout << k << ' ';
	cout << "\n";
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}

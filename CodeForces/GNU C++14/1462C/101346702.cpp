#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6;
const int MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	string s = to_string(n);
	if(s.size() == 1){
		cout << n << '\n';
		return;
	}
	if(n > 45){
		cout << "-1\n";
		return;
	}
	vector<int> ans;
	int mx = 9;
	while(n > 0){
		ans.push_back(min(mx, n));
		n -= min(mx, n);
		--mx;
	}
	sort(ans.begin(), ans.end());
	for(auto k : ans)
		cout << k;
	cout << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
	return 0;
}

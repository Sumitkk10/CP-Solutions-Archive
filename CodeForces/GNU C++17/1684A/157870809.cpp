#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 1e6, MOD = 1e9 + 7;

void solve(){
	string s;
	cin >> s;
	if(s.size() == 2){
		cout << s.back() << '\n';
		return;
	}
	int ans = INT_MAX;
	for(auto k : s)
		ans = min(ans, k - '0');
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
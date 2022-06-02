#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define ll long long
#define pii pair<long long, pair<int, int> >
#define F first 
#define S second
using namespace std;
const int N = 1e6 + 5;

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	string ans;
	bool ct = 1;
	for(int i = 0; i < n - 1; ++i){
		if(s[i] > s[i + 1] and ct){
			ct = 0;
			continue;
		}
		ans.pb(s[i]);
	}
	ans.pb(s[n - 1]);
	if(ans.size() == n)
		ans.pop_back();
	cout << ans << '\n';
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
}
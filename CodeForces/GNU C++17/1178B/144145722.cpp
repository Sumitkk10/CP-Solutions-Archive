#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define ll long long
#define F first 
#define S second
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;

void solve(){
	string s;
	cin >> s;
	int n = s.size();
	long long pre[n + 1], suf[n + 1];
	pre[0] = 0;
	for(int i = 1; i < n; ++i){
		if(s[i] == 'v' and s[i - 1] == 'v')
			pre[i] = pre[i - 1] + 1;
		else
			pre[i] = pre[i - 1];
	}
	suf[n - 1] = 0;
	for(int i = n - 2; i >= 0; --i){
		if(s[i] == 'v' and s[i + 1] == 'v')
			suf[i] = suf[i + 1] + 1;
		else
			suf[i] = suf[i + 1];
	}
	long long ans = 0;
	for(int i = 0; i < n; ++i){
		if(s[i] == 'o'){
			// cout << pre[i] << ' ' << suf[i] << endl;
			ans += pre[i] * suf[i];
		}
	}
	cout << ans << '\n';
}

int main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
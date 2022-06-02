#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define int long long
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;

void solve(){
	int n, k;
	cin >> n >> k;
	int first = n, last = -1;
	string s;
	cin >> s;
	for(int i = 0; i < n; ++i){
		if(s[i] == '1'){
			first = min(first, i);
			last = max(i, last);
		}
	}
	if(last == -1){
		cout << "0\n";
		return;
	}
	bool ok = 0;
	if((n - last - 1) <= k){
		k -= (n - last - 1);
		swap(s[n - 1], s[last]);
		ok = 1;
	}
	if((first != last or (first == last and !ok)) and first <= k){
		k -= first;
		swap(s[0], s[first]);
	}
	int ans = 0;
	for(int i = 0; i < n - 1; ++i)
		ans += (s[i] - '0') * 10 + (s[i + 1] - '0');
	cout << ans << '\n';
}

int32_t main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
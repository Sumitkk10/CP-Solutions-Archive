#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	long long q;
	cin >> q;
	map<int, int> mp;
	long long lft = 1e6, rt = 1e6;
	--q;
	char a;
	int val;
	cin >> a >> val;
	mp[val] = lft;
	while(q--){
		cin >> a;
		cin >> val;
		if(a == 'L'){
			--lft;
			mp[val] = lft;
		}
		else if(a == 'R'){
			++rt;
			mp[val] = rt;
		}
		else
			cout << min(mp[val] - lft, rt - mp[val]) << '\n';
	}
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}

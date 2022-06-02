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
	map<int, int> mp;
	bool ok = 1;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		mp[x]++;
		if(mp[x] >= 2)
			ok = 0;
	}
	cout << (ok ? "prekrasnyy\n" : "ne krasivo\n");
}

int main(){
	fast;
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}

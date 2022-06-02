#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
int n, q, pos, a[N];

void solve(){
	cin >> n >> q;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		pos += (a[i] > 0);
	}
	while(q--){
		int type, x;
		cin >> type >> x;
		if(type == 1){
			pos += (a[x] ? -1 : 1);
			a[x] = 1 - a[x];
		}
		else{
			if(pos >= x) cout << "1\n";
			else cout << "0\n";
		}
	}
}
 
int main() {
	fast;
	int t = 1;
 	// cin >> t;
	while(t--)
		solve();
	return 0;
}   
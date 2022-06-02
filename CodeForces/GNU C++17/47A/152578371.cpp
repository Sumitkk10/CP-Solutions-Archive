#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 1e6, MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i){
		long long x = (i * (i + 1)) / 2;
		if(x == n){
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}
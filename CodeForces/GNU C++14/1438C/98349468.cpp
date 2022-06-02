#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			int x;
			cin >> x;
			if((i + j) % 2 == 0 && x % 2 != 0)
				cout << x + 1 << ' ';
			else if((i + j) % 2 && x % 2 == 0)
				cout << x + 1 << ' ';
			else
				cout << x << ' ';
		}
		cout << '\n';
	}
}

int main(){
	fast;
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}

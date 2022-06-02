#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int n, k;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	int mn = INT_MAX;
	for(int x = 1; x <= 101; ++x){
		int ans = 0;
		for(int i = 0; i < n; ++i){
			int ok = 0;
			if(a[i] != x){
				for(int j = 0; j < k; ++j){
					if(i > n) 
						break;
					ok += (a[i] != x);
					++i;
				}
				if(ok) ++ans;
				--i;
			}
		}
		mn = min(mn, ans);
	}
	cout << mn << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}

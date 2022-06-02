#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	int t;
	cin >> t;
	while(t--){
		int n, m, x;
		cin >> n >> m;
		map<int, int> mp, mpp;
		for(int i = 0; i < n; ++i){
			cin >> x;
			mp[x]++;
		}
		for(int i = 0; i < m; ++i){
			cin >> x;
			mpp[x]++;
		}
		int ans = 0;
		for(auto k : mpp){
			if(mp[k.first])
				ans += mp[k.first];
		}
		cout << ans << "\n";
	}
	return 0;
}

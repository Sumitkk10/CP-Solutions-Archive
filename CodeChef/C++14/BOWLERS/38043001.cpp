#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int main(){
	fast;
	ll t;
	cin >> t;
	while(t--){
		ll n, k, m;
		cin >> n >> k >> m;
		// n = total overs, k = no of bowlers, and m = atmost m overs by one bowler;
		vector<int> ans;
		ll cnt = 1, hash[n + 1] = {0};
		for(int i = 0; i < n; ++i){
			if(hash[cnt] == -1) continue;
			hash[cnt]++;
			ans.push_back(cnt);
			if(hash[cnt] == m)
				hash[cnt] = -1;
			++cnt;
			if(cnt == k + 1) cnt = 1;
		}
		bool ok = 0;
		for(int i = 1; i < ans.size(); ++i){
			if(ans[i] == ans[i - 1]){
				ok = true;
				break;
			}
		}
		if(ok || ans.size() != n) cout << "-1\n";
		else{
			for(auto k : ans) cout << k << " ";
			cout << "\n";
		}
	}
	return 0;
}

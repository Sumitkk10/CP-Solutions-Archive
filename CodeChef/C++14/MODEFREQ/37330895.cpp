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
		ll n;
		cin >> n;
		ll a[n];
		map<int, int> mp, mpp;
		for(int i = 0; i < n; ++i){
			cin >> a[i];
			mp[a[i]]++;
		}
		for(auto i : mp) 
			mpp[i.second]++;
		int mx = 0, ans = 1e9;
		for(auto i : mpp){
			// cout << i.second << " " << i.first << " ";
			if(i.second >= mx){
				if(ans == 1e9) ans = i.first;
				else if(mx == i.second)
					ans = min(ans, i.first);
				else if(i.second > mx)
					ans = i.first;
				mx = i.second;
			} 
		}
		cout << ans << "\n";
	}
	return 0;
}

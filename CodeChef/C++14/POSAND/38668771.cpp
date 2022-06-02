#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

bool ispower_2(int n){
	if(n == 1) return false;
	return (ceil(log2(n)) == floor(log2(n)));
}

int main(){
	fast;
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		if(ispower_2(n)){
			cout << "-1\n";
			continue;
		}
		if(n == 1){
			cout << "1\n";
			continue;
		}
		vector<ll> ans;
		ans.push_back(2);
		ans.push_back(3);
		ans.push_back(1);
		for(int i = 4; i <= n; ++i){
			if(ispower_2(i)){
				ans.push_back(i + 1);
				ans.push_back(i);
				++i;
			}
			else ans.push_back(i);
		}
		for(auto k : ans)cout << k << " ";
		cout << "\n";
	}
	// cout << (9 & 8) << "\n";
	return 0;
}

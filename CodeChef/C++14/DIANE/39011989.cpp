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
		ll d;
		cin >> d;
		if(d == 0){
			cout << "2\n" << "1 1\n";
			continue;
		}
		if(d < 10000){
			cout << "5\n";
			cout << d << " " << d + 1 << " 1 " << "2 3\n";
			continue; 
		}
		vector<ll> ans;
		long long int k = 99999;
		while(d > 0){
			if(d < k)
				k = d + 1;
			d -= (k - 1);
			ans.push_back(k);
			ans.push_back(k + 1);
			ans.push_back(1);
		}
		cout << ans.size() << "\n";
		for(auto k : ans)
			cout << k << " ";
		cout << "\n";
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
 
int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		unordered_map<ll, ll> mp;
		ll n, r, x, y;
		cin >> n >> r >> x >> y;
		for(int i = 0; i < x; i++){
			ll no;
			cin >> no;
			mp[no]++;
		}
		for(int i = 0; i < y; i++){
			ll no;
			cin >> no;
			mp[no]++;
		}
		ll ele = n - mp.size();
		cout << min(r, ele) << "\n";
	}
 
	return 0;
}
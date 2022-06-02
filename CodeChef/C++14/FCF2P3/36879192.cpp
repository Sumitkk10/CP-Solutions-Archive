#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1e4 + 3;

int main(){
	fast;
	ll t; cin >> t;
	while(t--){
		ll n, k, m;
		cin >> n >> k >> m;
		ll a[n], b[k - 1], sum = 0;
		priority_queue<int> large;
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		for(int i = 0; i < n; ++i){ 
			sum += a[i];
			large.push(a[i]);
		}
		while(large.size() > m){
			sum -= large.top();
			large.pop();
		}
		for(int i = 0; i < k - 1; ++i) cin >> b[i];
		cout << sum << " ";
		for(int i = 0; i < k - 1; ++i){
			large.push(b[i]);
			sum += b[i];
			sum -= large.top();
			large.pop();
			cout << sum << " ";
		}
		cout << "\n";
	}
	cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
	return 0;
}
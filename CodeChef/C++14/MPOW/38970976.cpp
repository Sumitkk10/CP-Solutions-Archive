#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

int main(){
	fast;
	ll t;
	cin >> t;
	ll mul[N];
	mul[0] = mul[1] = 1;
	for(int i = 2; i < N; ++i)
		mul[i] = (mul[i - 1] * i) % MOD;
	while(t--){
		ll n;
		cin >> n;
		ll a[n];
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		stack<pair<int, int> > stk;
		int mx = 0;
		for(int i = 0; i < n; ++i){
			int pre = i;
			while(!stk.empty() && stk.top().first <= a[i]){
				pre = stk.top().second;
				stk.pop();
			}
			stk.push({a[i], pre});
			mx = max(mx, i - pre);
		}
		cout << mul[mx + 1] << "\n";
	}
	return 0;
}

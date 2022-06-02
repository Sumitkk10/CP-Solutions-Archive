#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	ll n;
	cin >> n;
	ll a[n];
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a+n);
	ll ans = 0, sum = 0;
	for(int i = 0; i < n; ++i){
		sum += a[i];
		if(sum > 500) break;
		++ans;
	}
	cout << ans << "\n";
	return 0;
}

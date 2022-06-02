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
	ll pre_sum[n + 1] = {0}, a[n], suffix_sum[n + 2] = {0};
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		pre_sum[i + 1] = pre_sum[i] + a[i];
	}
	if(pre_sum[n] % 3){
		cout << "0\n";
		return 0;
	}
	ll sum = pre_sum[n] / 3;
	for(int i = n - 1; i >= 0; --i)
		suffix_sum[i + 1] = suffix_sum[i + 2] + a[i];
	for(int i = n - 1; i >= 0; --i)
		suffix_sum[i + 1] = (suffix_sum[i + 1] == sum) + suffix_sum[i + 2];
	ll ans = 0;
	for(int i = n - 2; i >= 1; --i)
		if(pre_sum[i] == sum)
			ans += suffix_sum[i + 2];
	cout << ans << "\n";
	return 0;
}
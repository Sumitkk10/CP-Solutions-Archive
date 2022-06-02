#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e8;

void solve(){
	int n;
	cin >> n;
	int a[n + 1];
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	map<int, int> dp;
	long long int ans = 0, index; 
	for(int i = 1; i <= n; ++i){
		if(!dp[a[i]]) dp[a[i]]++;
		dp[a[i]] = max(dp[a[i]], dp[a[i] - 1] + 1);
		if(dp[a[i]] > ans){
			ans = dp[a[i]];
			index = a[i];
		}
	}
	cout << dp[index] << '\n';
	int str = index - dp[index] + 1;
	for(int i = 1; i <= n; ++i){
		if(a[i] == str){
			cout << i << ' ';
			++str;
		}
	}
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}

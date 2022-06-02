#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 100000;
const int MOD = 1e9 + 7;

int main(){
	fast;
	int n;
	cin >> n;
	long long int dp[N + 1] = {0}, mp[N] = {0};
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		mp[x]++;
	}
	dp[1] = mp[1];
	for(int i = 2; i <= N; ++i)
		dp[i] = max(dp[i - 1], dp[i - 2] + (mp[i] * i));
	cout << dp[N];
	return 0;
}

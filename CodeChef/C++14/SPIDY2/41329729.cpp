#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int main(){
	fast;
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	ll dp[n + 1] = {0};
	dp[n - 1] = 0;
	for(int i = n - 2; i >= 0; --i){
		dp[i] = LLONG_MAX;
		for(int j = 1; j; j *= 2){
			int jump = i + j;
			if(jump >= n)
				break;
			dp[i] = min(dp[i], dp[jump] + abs(a[jump] - a[i]));
		}
	}
	cout << dp[0] << '\n';
	return 0;
}

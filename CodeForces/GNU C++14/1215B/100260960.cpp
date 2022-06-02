#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	long long int n;
	cin >> n;
	long long int a[n], dp[n][2];
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	if(a[0] >= 0){
		dp[0][0] = 0;
		dp[0][1] = 1;
	}
	else{
		dp[0][0] = 1;
		dp[0][1] = 0;
 	}
 	long long int cnt = dp[0][0], cnt1 = dp[0][1];
 	for(int i = 1; i < n; ++i){
 		if(a[i] > 0){
 			dp[i][1] = dp[i - 1][1] + 1;
 			dp[i][0] = dp[i - 1][0];
 		}
 		else{
 			dp[i][0] = dp[i - 1][1] + 1;
 			dp[i][1] = dp[i - 1][0];
 		}
 		cnt += dp[i][0];
 		cnt1 += dp[i][1];
 	}
 	cout << cnt << ' ' << cnt1 << '\n';
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();	
	return 0;
}

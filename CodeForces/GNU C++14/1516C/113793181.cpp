#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int K = 200005, N = 106;
const int MOD = 1e9 + 7;
long long n, a[N], sum;
bool dp[N][K + 1];

void solve(){
	long long int ok = -1;
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		sum += a[i];
		if(a[i] % 2 != 0)
			ok = i;
	}
	if(sum % 2){
		cout << "0\n";
		return;
	}
	dp[0][0] = 1;
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j <= K; ++j){
			dp[i][j] |= dp[i - 1][j];
			if(j >= a[i])
				dp[i][j] |= (dp[i - 1][j - a[i]]);
		}
	}
	sum /= 2;
	if(dp[n][sum] == 0){
		cout << "0\n";
		return;
	}
	if(ok != -1){
		cout << "1\n" << ok << '\n';
		return;
	}
	while(true){
		for(int i = 1; i <= n; ++i){
			if(a[i] % 2){
				cout << "1\n" << i << '\n';	
				return;
			}
			a[i] /= 2;
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
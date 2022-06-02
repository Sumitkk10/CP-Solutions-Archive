#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e8;
int n, k, number, number1;
long long int dp[101][101][11][11];

long long int go(int cnt, int cnt1, int cons, int cons1){
	if(cnt + cnt1 >= n + k) 
		return 1;
	if(dp[cnt][cnt1][cons][cons1] != -1) 
		return dp[cnt][cnt1][cons][cons1];
	long long int ans = 0;
	if(cons < number && cnt < n) 
		ans = (ans + go(cnt + 1, cnt1, cons + 1, 0)) % MOD;
	if(cons1 < number1 && cnt1 < k) 
		ans = (ans + go(cnt, cnt1 + 1, 0, cons1 + 1)) % MOD;
	return dp[cnt][cnt1][cons][cons1] = ans;
}

void solve(){
	memset(dp, -1, sizeof(dp));
	cin >> n >> k >> number >> number1;
	cout << go(0, 0, 0, 0) << '\n';
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}

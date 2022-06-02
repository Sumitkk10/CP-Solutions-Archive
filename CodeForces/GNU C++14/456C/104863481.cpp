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
	long long int a[n];
	unordered_map<long long int, long long int> mp;
	for(int i = 0; i < n; ++i){
	    cin >> a[i];
	    mp[a[i]]++;
	}
	long long int ans[N] = {0};
	for(long long int i = 0; i < N; ++i)
	    ans[i] = (mp[i] * i);
	long long int dp[N] = {0};
	dp[0] = ans[0];
	for(int i = 1; i < N; ++i)
	    dp[i] = max(ans[i] + dp[i - 2], dp[i - 1]);
	cout << dp[N - 1] << endl;
	return 0;
}

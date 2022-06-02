#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
unordered_map<int, ll> dp;

long long int solve(int x){
	if(x == 0)
		return 0;
	if(dp[x] != 0)
		return dp[x];
	long long int ok = solve(x / 2) + solve(x / 3) + solve(x / 4);
	if(ok > x)
		return dp[x] = ok;
	return dp[x] = x;
}

int main(){
	fast;
	int x;
	while(cin >> x)
		cout << solve(x) << '\n';
	return 0;
}

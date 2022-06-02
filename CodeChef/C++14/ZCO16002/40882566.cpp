#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
int n, a[N], dp[2501][2501], location[N];

long long int solve(int i, int j){
	if(i < 0 or j < 0 or i >= n or j >= n) 
		return dp[i][j] = 0;
	if(dp[i][j] != -1)
		return dp[i][j];
	if(i == 0)
		return dp[i][j] = 2;
	int diff = a[j] - a[i];
	int pre = a[i] - diff;
	if(pre < 0)
		return dp[i][j] = 2;
	if(location[pre] != -1)
		return dp[i][j] = solve(location[pre], i) + 1;
	else
		return dp[i][j] = 2;
}

int main(){
	fast;
	memset(location, -1, sizeof(location));
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];	
	sort(a, a + n);
	for(int i = 0; i < n; ++i)
		location[a[i]] = i;
	memset(dp, -1, sizeof(dp));
	long long int ans = 0;
	for(int i = 0; i < n; ++i)
		for(int j = i + 1; j < n; ++j)
			ans = max(ans, solve(i, j));
	cout << ans << '\n';
	return 0;
}
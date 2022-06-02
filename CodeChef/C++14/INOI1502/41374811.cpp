#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int n, m;

long long int power(int x, int y){
	if(y == 1)
		return x;
	long long int res = (power(x, y / 2)) % m;
	if(y % 2)
		return ((res * res * x) % m);
	return ((res * res) % m);
}

int main(){
	fast;
	cin >> n >> m;
	// no. of non - periodic strings of length n : 
	// 2^n - no. of periodic strings of length n.
	long long int dp[n + 1] = {0};
	dp[1] = 2;
	for(int i = 2; i <= n; ++i){
		dp[i] = power(2, i) - 2;
		for(int j = 2; j * j <= i; ++j){
			if(i % j == 0){
				dp[i] -= dp[j];
				dp[i] += m;
				dp[i] %= m;
				if(i/j != j){
					dp[i] -= dp[i/j];
					dp[i] += m;
					dp[i] %= m;
				}
			}
		}
	}
	cout << dp[n] << '\n';
	return 0;
}

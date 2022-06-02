#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
#define MAX 10002
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

long long int func(long long int ind, long long int g, long long int dp[][MAX], long long int n, long long int a[]){
    if(ind == n){
        if(g == 1)
            return 1;
        else
            return 0;
    }
    if(dp[ind][g] != -1)
        return dp[ind][g];
    long long int ans = func(ind + 1, g, dp, n, a) + func(ind + 1, __gcd(a[ind], g), dp, n, a);
    return dp[ind][g] = ans;
}

long long int countSubsequences(long long int a[], long long int n){
    long long int dp[n][MAX];
    memset(dp, -1, sizeof dp);
    long long int count = 0;
    for(long long int i = 0; i < n; i++)
        count += func(i + 1, a[i], dp, n, a);
    return count;
}

int main(){
	fast;
	long long int t;
	cin >> t;
	while(t--){
		long long int n;
		cin >> n;
		long long int a[n];
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		cout << countSubsequences(a, n) << "\n";
	}
	return 0;
}

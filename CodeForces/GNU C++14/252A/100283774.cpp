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
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	long long int ans = 0;
	for(int k = 1; k <= n; ++k){
		for(int i = k - 1; i < n; ++i){
			long long int xorr = a[i]; 
			for(int j = max(0, i - k + 1); j < i; ++j)
				xorr = (xorr ^ a[j]);
			ans = max(ans, xorr);
		}
	}
	cout << ans;
	return 0;
}

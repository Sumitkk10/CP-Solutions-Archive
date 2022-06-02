#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int n, k;
	cin >> n >> k;
	long long ones = 0, pre[n], a[n];
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		ones += a[i];
		if(!i)
			pre[i] = a[i];
		else
			pre[i] = pre[i - 1] + a[i];
	}
	long long mn = n;
	for(int i = k - 1; i < n; ++i){
		if(i == k - 1)
			mn = min(mn, pre[i]);
		else
			mn = min(mn, pre[i] - pre[i - k]);
	}
	cout << ((mn*(mn + 1)) / 2) + ones - mn << "\n";
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}

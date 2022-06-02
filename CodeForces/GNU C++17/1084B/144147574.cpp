#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define ll long long
#define F first 
#define S second
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;

void solve(){
	long long n, k;
	cin >> n >> k;
	long long a[n], sum = 0, mn = INT_MAX;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		sum += a[i];
		mn = min(mn, a[i]);
	}
	if(sum < k){
		cout << "-1\n";
		return;
	}
	long long low = 0, high = mn, ans;
	while(low <= high){
		long long mid = (low + (high - low) / 2);
		sum = 0;
		for(int i = 0; i < n; ++i)
			sum += a[i] - mid;
		if(sum >= k){
			ans = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	cout << ans << '\n';
}

int main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
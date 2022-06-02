#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

void solve(){
	int n;
	cin >> n;
	long long int a[n], l, r, ans = 0;
	cin >> l >> r;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n);
	for(int i = 0; i < n; ++i){
		long long int x = a[i];
		if(x > r) break;
		long long int low = i + 1, high = n - 1, ok = -1;
		while(low <= high){
			long long int mid = (low + high) / 2;
			if(x + a[mid] >= l){
				ok = mid;
				high = mid - 1;
			}
			else
				low = mid + 1;
		}
		if(ok == -1) continue;
		low = i + 1, high = n - 1;
		long long int okk = -1;
		while(low <= high){
			long long int mid = (low + high) / 2;
			if(x + a[mid] <= r){
				okk = mid;
				low = mid + 1;
			}
			else
				high = mid - 1;
		}
		if(okk == -1) continue;
		ans += okk - ok + 1;
	}
	cout << ans << '\n';
}
 
int main() {
	fast;
	int t = 1;
 	cin >> t;
	while(t--)
		solve();
	return 0;
}
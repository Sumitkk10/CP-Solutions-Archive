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
	int a[n];
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n);
	int low = 0, high = 1e9, ans = -1;
	while(low <= high){
		int mid = (low + high) / 2;
		int pre = a[0], place = 1;
		for(int i = 1; i < n; ++i){
			if(a[i] >= pre + mid){
				++place;
				pre = a[i];
			}
		}
		if(place >= k){
			ans = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	cout << ans << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}

#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	ll n, q;
	cin >> n >> q;
	ll a[n];
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a+n);
	ll pre[n + 1];
	pre[0] = a[0];
	for(int i = 1; i < n; ++i)
		pre[i] = pre[i - 1] + a[i];
	while(q--){
		int b;
		cin >> b;
		b *= 2;
		int low = 0, high = n - 1, ans = n;
		while(low <= high){
			int mid = (low + high) / 2;
			if(a[mid] >= b){
				high = mid - 1;
				ans = mid;
			}
			else low = mid + 1;
		}
		if(ans == 0) cout << pre[n - 1] << "\n";
		else cout << pre[n - 1] - pre[ans - 1] << "\n";	
	}
	return 0;
}
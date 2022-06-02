#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define F first
#define S second
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	long long int a[n];
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	long long ans = 0;
	for(int i = 0; i < n - 2; ++i){
		long long mx = a[i], mn = a[i];
		mx = max(mx, a[i + 1]);
		mn = min(mn, a[i + 1]);
		for(int j = i + 2; j < n; ++j){
			mx = max(mx, a[j]);
			mn = min(mn, a[j]);
			int low = i, high = j, find = (mx + mn) / 2, res = i;
			while(low <= high){
				int mid = (low + high) / 2;
				if(a[mid] >= find){
					res = mid;
					high = mid - 1;
				}
				else
					low = mid + 1;
			}
			long long cur = (mx - a[res]) * (a[res] - mn);
			if(res != i)
				cur = max(cur, (mx - a[res - 1]) * (a[res - 1] - mn));
			if(res != j)
				cur = max(cur, (mx - a[res + 1]) * (a[res + 1] - mn));
			ans += cur;
		}
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
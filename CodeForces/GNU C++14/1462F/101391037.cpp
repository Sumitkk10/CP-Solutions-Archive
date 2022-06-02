#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	pair<int, int> a[n], b[n];
	for(int i = 0; i < n; ++i){
		cin >> a[i].first >> a[i].second;
		b[i].first = a[i].second;
		b[i].second = a[i].first;
	}
	long long int ans = 0;
	sort(a, a + n);
	sort(b, b + n);
	for(int i = 0; i < n; ++i){
		int x = a[i].second;
		int low = i + 1, high = n - 1, ans1 = i;
		while(low <= high){
			int mid = (low + high) / 2;
			if(a[mid].first <= x){
				ans1 = mid;
				low = mid + 1;
			}
			else
				high = mid - 1;
		}
		x = a[i].first;
		low = 0, high = i - 1;
		int ans2 = i;
		while(low <= high){
			int mid = (low + high) / 2;
			if(b[mid].first >= x){
				ans2 = mid;
				high = mid - 1;
			}
			else
				low = mid + 1;
		}
		ans = max(ans, (ll) (i - ans2) + (ans1 - i));
	}
	cout << n - ans - 1 << '\n'; 
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}

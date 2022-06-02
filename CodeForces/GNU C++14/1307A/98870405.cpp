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
	int a[n], idx = -1;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		if(i != 0 and a[i] and idx == -1)
			idx = i;
	}
	long long int ans = a[0];
	// cout << idx << ' ';
	while(k > 0){
		if(idx >= n || idx == -1 || idx > k) break;
		if(a[idx] != 0){
			a[idx]--;
			++ans;
			k -= abs(idx);
		}
		else{
			while(!a[idx])
				++idx;
		}
	}
	cout << ans << '\n';
}

int main(){
	fast;
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}

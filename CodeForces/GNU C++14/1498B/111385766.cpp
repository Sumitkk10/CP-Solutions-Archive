#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int highestPowerof2(int n){
   int p = (int)log2(n);
   return (int)pow(2, p);
}

void solve(){
	int n, k;
	cin >> n >> k;
	int a[n];
	map<int, int> mp;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		mp[a[i]]++;
	}
	int nn = n, ans = 0;
	while(nn > 0){
		int cur = k;
		int ok = highestPowerof2(cur);
		while(ok > 0 and cur > 0){
			if(mp[ok] > 0){
				mp[ok]--;
				--nn;
				cur -= ok;
				ok = highestPowerof2(cur);
			}
			else
				ok /= 2;
		}
		++ans;
	}
	cout << ans << "\n";
}

int main(){
    fast;
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
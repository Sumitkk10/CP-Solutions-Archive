#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define F first
#define S second
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
long long k, x;

void solve(){
	cin >> k >> x;
	long long low = 0, high = 2*k - 1, ans = 0;
	while(low <= high){
		long long mid = (low + high) / 2;
		if(mid <= k){
			long long emotes = (mid * (mid + 1))/2;
			if(emotes < x)
				low = mid + 1;
			else{
				high = mid - 1;
				ans = mid;
			}
		}
		else{
			long long emotes = (k * (k + 1))/2;
			long long rem = mid - k;
			long long cur = (k * (k - 1))/2, ok = k - rem - 1;
			cur -= (ok * (ok + 1)) / 2;
			if(cur + emotes < x)
				low = mid + 1;
			else{
				high = mid - 1;
				ans = mid;
			}
		}
	}
	cout << (ans == 0 ? 2*k - 1 : ans) << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
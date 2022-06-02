#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 5e5 + 5, MOD = 1e9 + 7;

void solve(){
	int n, k;
	cin >> n >> k;
	long long low = 1, high = 1e16, res;
	while(low <= high){
		long long mid = (low + (high - low) / 2);
		long long x = mid / n;
		if(mid - x >= k){
			res = mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	cout << res << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
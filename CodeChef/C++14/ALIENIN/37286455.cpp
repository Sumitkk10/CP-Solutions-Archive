#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;

int main(){
	fast;
	ll t;
	cin >> t;
	while(t--){
		ll n, d;
		cin >> n >> d;
		ld c[n];
		for(int i = 0; i < n; ++i)
			cin >> c[i];
		sort(c, c+n);
		ld low = 0, high = 1e10, ans1 = 0;
		while(low + EPS <= high){
			ld mid = (low + high) / 2;
			ld mn = c[0];
			bool ans = 0;
			for(int i = 1; i < n; ++i){
				mn += mid;
				if(mn > (c[i] + d)){
					ans = true;
					break;
				}
				else if(mn < c[i])  mn = c[i] ;
			}
			if(ans)
				high = mid - EPS;
			else{
				ans1 = mid;
				low = mid + EPS;
			}
		}
		cout << fixed << setprecision(9) << ans1 << "\n";
	}
	return 0;
}
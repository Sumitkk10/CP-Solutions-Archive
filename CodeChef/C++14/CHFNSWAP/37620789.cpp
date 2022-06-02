#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int main(){
	fast;
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		ll r = (n * (n + 1)) / 2;
		if(r%2){
			cout << "0\n";
			continue;
		}
		ll low = 1, high = n - 1, ans = 0;
		while(low <= high){
			ll mid = (low + high) / 2;
			ll sum = mid * (mid + 1) / 2;
			sum = r - sum;
			if(sum < r / 2) high = mid - 1;
			else if(sum >= r / 2){
				ans = mid;
				low = mid + 1;
			}
		}
		ll a = ans;
		ll sum = a * (a + 1) / 2;
		ans = n - ans;
		if(sum == r / 2){
			if(a == 1) ans += n-a * (n - a - 1) / 2;
			else if(n - a == 1) ans += a * (a - 1) / 2;
			else ans += (n - a) * (n - a - 1) / 2 + (a * (a - 1)) / 2; 
		}
		cout << ans << "\n";
	}
	return 0;
}

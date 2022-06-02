#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int main() {
	fast;
	int t = 1;
	// cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int odd[n], even[n], a[n], sum = 0;
		memset(odd, 0, sizeof(odd));
		memset(even, 0, sizeof(even));
		for(int i = 0; i < n; ++i){
			cin >> a[i];
			if(!i){
				odd[i] = a[i];
				odd[1] = a[0];
			}
			else if(i % 2 == 0){ 
				odd[i] = odd[i - 1] + a[i];
				odd[i + 1] = odd[i];
			}
			else{ 
				even[i] = even[i - 1] + a[i];
				even[i + 1] = even[i];
			}
			sum += a[i];
		}
		int ans = 0;
		for(int i = 0; i < n; ++i){
			if(i % 2 == 0){
				int od = odd[i] - a[i] + even[n - 1] - even[i];
				int eve = sum - od;
				eve -= a[i];
				ans += (od == eve);
				// cout << i << ' ' << od << ' ' << eve << '\n';
			}
			else{
				int eve = even[i] - a[i] + odd[n - 1] - odd[i];
				int od = sum - eve;
				od -= a[i];
				ans += (od == eve);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

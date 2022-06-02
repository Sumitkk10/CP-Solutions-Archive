#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	int n;
	cin >> n;
	long long int a[n];
	map<long long int, int> mp;
	for(int i = 0; i < n; ++i){
		cin >> a[i];	
		mp[a[i]]++;
	}
	int ans = 0;
	for(ll k : a){
		bool ok = 0;
		for(int i = 0; i <= 30; ++i){
			long long int x = pow(2, i);
			if(mp.count(x - k)){
				if(2 * k == x)
					ok = (mp[k] > 1);	
				else ok = 1;
			}
		}
		ans += (ok == 0);
	}
	cout << ans << '\n';
	return 0;
}

#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	ll n, k, s;
	cin >> n >> k >> s;
	ll a[n], sum = 0; 
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		sum += a[i];
	}
	if(sum <= s || k >= n) cout << "-1\n";
	else{
		sort(a, a+n, greater<>());
		sum = 0;
		int i = 0, cnt = 0;
		while(sum <= s || cnt <= k){
			sum += a[i];
			++cnt;
			++i;
		}

		cout << cnt << "\n";	
	}
	return 0;
}

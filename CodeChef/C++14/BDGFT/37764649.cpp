#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int main(){
	fast;
	ll t = 1;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		ll n  = s.size(), ans = 0, kk, ct0 = 0, ct1 = 0;
		for(int k = 1; k*k+k <= n; ++k){
			ct0 = 0, ct1 = 0, kk = k*k + k;
			for(int i = 0; i < kk; ++i){
				if(s[i] == '0') ++ct0;
				else ++ct1;
			}
			if(ct1 == k) ++ans;	
			for(int i = kk; i < n; ++i){
				if(s[i - kk] == '0') --ct0;
				else --ct1;
				if(s[i] == '0') ++ct0;
				else ++ct1;
				if(ct1 == k) ++ans;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
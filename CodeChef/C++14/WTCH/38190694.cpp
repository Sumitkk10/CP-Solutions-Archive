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
		ll n, ans = 0; 
		cin >> n;
		string s;
		cin >> s;
		for(int i = 0; i < n; ++i){
			if(s[i] == '0' && (s[i + 1] == '0' || i == n - 1)){
				++ans;
				++i;
			}
			else if(s[i] == '1') ++i;
		}
		cout << ans << "\n";
	}
	return 0;
}

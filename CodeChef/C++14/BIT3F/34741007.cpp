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
		string s;
		cin >> s;
		ll ans = 0;
		for(int i = 0; i < s.size(); ++i){
			if(s[i] != 'a' and s[i] != 'i' and s[i] != 'e' and s[i] != 'o' and s[i] != 'u'){
				ans += min(abs(s[i] - 'a'), min(abs(s[i] - 'i'), min(abs(s[i] - 'e'), min(abs(s[i] - 'o'), abs(s[i] - 'u')))));
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

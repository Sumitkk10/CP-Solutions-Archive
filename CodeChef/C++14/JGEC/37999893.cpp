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
		for(int i = 0; i <= n - 4; ++i)
			if(s[i] == 'J' && s[i + 1] == 'G' && s[i + 2] == 'E' && s[i + 3] == 'C')
				++ans;
		cout << ans << "\n";
	}
	return 0;
}

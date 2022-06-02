#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
	fast;
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		ll x = 0, y = 0;
		string s;
		cin >> s;
		for(ll i = 0; i < n; i++){
			if(s[i] != s[i-1] || i == 0){
				if(s[i] == 'R' && s[i-1] != 'L' || s[i] == 'L' && s[i-1] != 'R' || i == 0 || s[i] == 'U' && s[i-1] != 'D' || s[i] == 'D' && s[i-1] != 'U'){
					if(s[i] == 'L') x -= 1;
					else if(s[i] == 'R') x += 1;
					else if(s[i] == 'U') y += 1;
					else if(s[i] == 'D') y -= 1;
				} 
			}
		}
		cout << x << ' ' << y << '\n';
	}
	return 0;
}
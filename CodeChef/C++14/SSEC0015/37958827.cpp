#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	string s;
	cin >> s;
	ll mx = 0, str = 0, end = 0;
	for(int i = 0; i < s.size(); ++i){
		ll ans = s[i] - '0', j = i + 1;
		for(j = i + 1; j < s.size(); ++j){
			if(s[j] - '0' > s[i] - '0')
				ans += s[j] - '0';
			else
				break;
		}
		if(ans > mx){
			mx = ans;
			str = i + 1;
			end = j;
		}
	}
	cout << mx << ":" << str << "-" << end;
	return 0;
}

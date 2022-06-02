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
		for(int i = 0; i < s.size(); ++i){
			if(s[i] == '0'){
				s[i] = '8';
				continue;
			}
			if(s[i] == '1'){
				s[i] = '9';
				continue;
			}
			s[i] = ((s[i] - '0') - 2) + '0';
		}
		cout << s << "\n";
	}
	return 0;
}
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
		string s;
		cin >> s;
		ll cnt = 0;
		for(int i = 0; i < s.size(); i += 2){
			if(s[i] == 'A' && s[i+1] != 'B' || s[i] == 'B' && s[i+1] != 'A')
				cnt++;
		}
		if(cnt > 0) cout << "no\n";
		else
			cout << "yes\n";
	}
	return 0;
} 
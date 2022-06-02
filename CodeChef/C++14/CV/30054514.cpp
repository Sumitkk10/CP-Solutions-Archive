#include<bits/stdc++.h>
#define ll long long int
#define ld long doubles
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int main()
{
	fast;
	ll t;
	cin >> t;
	while(t--){
		ll a, ans = 0, i;
		cin >> a;
		string s;
		cin >> s;
		for(i = 0 ; i < a; i++){
			if(s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u')
				if(s[i+1] == 'a' || s[i+1] == 'e' || s[i+1] == 'i' || s[i+1] == 'o' || s[i+1] == 'u')
					ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}
	

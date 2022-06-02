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
		string s;
		cin >> s;
		ll i, ans = 0, b = 0;
		for(i = 0; i < s.size(); i++){
			if(s[i] == '1') 
				ans++;
			else 
				b++;
		}
		if(ans == 1 || b == 1)
			cout << "Yes" << '\n';
		else
			cout << "No" << '\n';
	}
	return 0;
}
	


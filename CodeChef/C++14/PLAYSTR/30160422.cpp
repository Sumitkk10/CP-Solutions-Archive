#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int main()
{
	fast;
	ll t, i;
	cin >> t;
	while(t--){
		ll n, ans = 0, max = 0, ans1 = 0, max1 = 0;
		cin >> n;
		string s, f;
		cin >> s >> f;
		for(i = 0 ; i < n; i++){
			if(s[i] == '1') ans++;
			else max++;
		}
		for(i = 0 ; i < n; i++){
			if(f[i] == '1') ans1++;
			else max1++;
		}
		if(ans == ans1 && max == max1) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}
	

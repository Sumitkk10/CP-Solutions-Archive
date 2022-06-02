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
		ll s, i, ans = 0, aa = 0;
		cin >> s;
		ll a[s];
		for(i = 0; i < s; i++){
			cin >> a[i];
		}
		for(i = 0; i < s/2; i++){
			if(a[i+1] == a[i] + 1)
				ans++;
		}
		for(i = s/2; i < s; i++){
			if(a[i+1] == a[i] - 1)
				aa++;
		}
		if(s % 2 == 0)
			cout << "no" << '\n';
		else if(a[0] != 1)
			cout << "no" << '\n';
		else if(ans != s/2)
			cout << "no" << '\n';
		else if(aa != s/2)
			cout << "no" << '\n';
		else 
			cout << "yes" << '\n';
	}
	return 0;
}
	

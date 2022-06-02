#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n, ans;
		cin >> n;
		ans = n/5;
		for(int i = 25; i < 10000000000001; i *= 5){
			if(n/i == 0)
				break;
			else
				ans += n/i;
		}
		cout << ans << '\n';
	}
	return 0;
}
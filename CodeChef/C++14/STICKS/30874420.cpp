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
		ll a[n], cnt1 = 0;
		for(int i = 0; i < n; ++i) 
			cin >> a[i];
		ll b[1001] = {0}, cnt = 0, ans = 1;
		for(int i = 0; i < n; ++i)
			b[a[i]]++;
		for(int i = 0; i < 1001; ++i){
			if(b[i] >= 2){
				cnt++;
			if(b[i] >= 4) cnt1++;
			}
		}
		if(cnt < 2 && cnt1 == 0) 
			cout << -1 << '\n';
		else{
			cnt = 0;
			for(int i = 1000; i >= 0; --i){
				if(b[i] == 2 || b[i] == 3 || b[i] > 3 && cnt > 0){
					ans = ans*i;
					cnt++;
				}
				else if(b[i] > 3){
					cout << i * i << '\n';
					break;
				}
				if(cnt == 2) 
					break;
			}
			if(cnt == 2) cout << ans << '\n';
		}
	}
	return 0;
} 
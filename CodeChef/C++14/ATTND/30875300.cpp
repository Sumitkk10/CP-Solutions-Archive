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
		string f[n], l[n];
		for(int i = 0; i < n; i++){
			cin >> f[i] >> l[i];
		}
		ll cnt = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(i==j) continue;
				else{
					if(f[i] == f[j]){
						cout << f[i] << ' ' << l[i] << '\n';
						break;
					}
					else
						cnt++;
				}
			}
			if(cnt == n-1) cout << f[i] << '\n';
			cnt = 0;
		}
	}
	return 0;
} 
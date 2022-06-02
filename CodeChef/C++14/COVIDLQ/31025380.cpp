#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		ll a[n], cnt = 0, cnt1 = 0, w = 0;
		for(int i = 0; i < n; ++i){
			cin >> a[i];
		}
		for(int i = 0; i < n; ++i){
			if(a[i] == 1){
				for(int j = i + 1; j < n; ++j){
					if(a[j] == 1){
						w = j;
						break;
					}
				}
				if(w == 0){
					cout << "YES" << '\n';
					cnt++;
					break;
				}
				else{
					if(abs(w-i) > 5){
						w = 0;
						continue;
					}
					else if(abs(w-i) <= 5){
						cout << "NO" << '\n';
						cnt1++;
						w = 0;
						break;
					}
				}
			}
		}
		if(cnt == 0 && cnt1 == 0)
			cout << "YES" << '\n';
	}
	return 0;
}
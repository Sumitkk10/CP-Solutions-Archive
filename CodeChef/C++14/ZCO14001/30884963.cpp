#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
	fast;
	ll n, h;
	cin >> n >> h;
	ll a[n] , c[100001], cnt = 0;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < 100001; ++i){
		cin >> c[i];
		if(c[i] == 0) break;
	}
	ll j = 0;
	for(int i = 0; i < 100001; ++i){
		if(c[i] == 0)
			break;
		else{
			if(c[i] == 1){
				if(j == 0) j = 0;
				else{
					j -= 1;
				}
			}
			else if(c[i] == 2){
				if(j == (n-1)) j = n-1;
				else{
					j += 1;
				}
			}
			else if(c[i] == 3){
				if(a[j] == 0 || cnt != 0)
					continue;
				else{
					a[j] -= 1;
					cnt++;
				}
			}
			else if(c[i] == 4){
				if(a[j] == h || cnt == 0){
					continue;
				}
				else{
					a[j] += 1;
					cnt = 0;
				}
			}
		}
	}
	for(int i = 0; i < n; ++i){
		cout << a[i] << ' ';
	}
	return 0;
} 
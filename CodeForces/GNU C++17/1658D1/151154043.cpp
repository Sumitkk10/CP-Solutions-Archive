#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;

void solve(){
	int l, r;
	cin >> l >> r;
	int a[r + 1];
	for(int i = 0; i < r + 1; ++i)
		cin >> a[i];
	int mp[20] = {0}, mpp[20] = {0}, wut[r + 1][20];
	memset(wut, 0, sizeof wut);
	for(int i = 0; i < r + 1; ++i){
		int x = a[i], ct = 0;
		while(x > 0){
			mp[ct] += (x % 2);
			wut[i][ct] = (x % 2);
			x /= 2;
			++ct;
		}
		x = i;
		ct = 0;
		while(x > 0){
			mpp[ct] += (x % 2);
			x /= 2;
			++ct;
		}
	}
	for(int i = 0; i < r + 1; ++i){
		bool ok = 1;
		for(int j = 0; j <= 17; ++j){
			int req = mp[j];
			if(wut[i][j] == 0){
				if(mpp[j] != req){
					ok = 0;
					break;
				}
			}
			else{
				if(r + 1 - mpp[j] != req){
					ok = 0;
					break;
				}
			}
		}
		if(ok){
			cout << a[i] << '\n';
			return;
		}
	}
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
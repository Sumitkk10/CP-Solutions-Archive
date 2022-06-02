#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
ll n, s, a[N];

void solve(){
	cin >> n >> s;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	int l = 1, r = 1, ans = 0, pos_l = -1, pos_r = -1;
	long long cur = s;
	while(l <= n and r <= n){
		if(a[r] <= 0){
			if(abs(a[r]) <= cur){
				cur -= abs(a[r]);
				++r;
			}
			else{
				if(r - l > ans){
					ans = r - l;
					pos_l = l;
					pos_r = r - 1;
				}
				if(a[l] > 0) cur -= a[l];
				else cur += abs(a[l]);
				l = l + 1;
			}
			continue;
		}
		else{
			cur += a[r];
			++r;
		}
	}
	if(r - l > ans){
		pos_r = r - 1;
		pos_l = l;
	}
	if(pos_l == -1){
		cout << "-1\n";
		return;
	}
	cout << pos_l << ' ' << pos_r << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
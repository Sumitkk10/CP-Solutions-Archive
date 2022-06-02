#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int n, m;
	cin >> n >> m;
	char a[n][m];
	long long int ans = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> a[i][j];
			ans += (a[i][j] == '*');
		}
	}
	int cnt2[n][m];
	memset(cnt2, 0, sizeof(cnt2));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			int cnt = 0, cnt1 = 0;
			for(int jj = j + 1; jj < m; ++jj){
				if(a[i][jj] == '*')
					++cnt;
				else
					break;
			}
			for(int jj = j - 1; jj >= 0; --jj){
				if(a[i][jj] == '*')
					++cnt1;
				else
					break;
			}
			cnt2[i][j] = min(cnt, cnt1);
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(a[i][j] != '*') continue;
			for(int h = 1; h <= n - i; ++h){
				if(i + h >= n) break;
				if(a[i + h][j] != '*') break;
				bool ok = true;
				if(cnt2[i + h][j] < h)
					ok = false;
				if(ok)
					++ans;
				else 
					break;
			}
		}
	}
	cout << ans << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
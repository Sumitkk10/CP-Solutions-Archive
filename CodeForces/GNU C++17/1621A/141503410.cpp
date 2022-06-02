#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL) 
#define ll long long
#define F first 
#define S second
using namespace std;
const int N = 50, MOD = 1e9 + 7;
int n, k, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}, ans[N][N];
bool vis[N][N];

void wrong(int i, int j){
	for(int kk = 0; kk < n; ++kk)
		vis[kk][j] = 1;
	for(int kk = 0; kk < n; ++kk)
		vis[i][kk] = 1;
}

void solve(){
	cin >> n >> k;
	int ct = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			vis[i][j] = 0;
			ans[i][j] = 0;
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(!vis[i][j]){
				ans[i][j] = 1;
				++ct;
				wrong(i, j);
				for(int kk = 0; kk < 4; ++kk){
					int _i = i + dx[kk], _j = j + dy[kk];
					if(_i >= 0 and _j >= 0 and _i < n and _j < n)
						wrong(_i, _j);
				}
			}
		}
	}
	if(ct < k){
		cout << "-1\n";
		return;
	}
	int ok = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(ans[i][j] == 1) ++ok;
			if(ok <= k)
				cout << (ans[i][j] == 1 ? 'R' : '.');
			else
				cout << ".";
		}
		cout << '\n';
	}
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    	solve();
	return 0;
}
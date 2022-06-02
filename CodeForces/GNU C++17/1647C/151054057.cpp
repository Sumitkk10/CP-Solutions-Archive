#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 1e2 + 5, MOD = 1e9 + 7;
int n, m, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
bool a[N][N];

void solve(){
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			char x;
			cin >> x;
			a[i][j] = (x == '1');
		}
	}
	if(a[1][1] == 1){
		cout << "-1\n";
		return;
	}
	vector<pair<int, pair<int, pair<int, int> > > > ans;
	for(int i = n; i >= 2; --i){
		for(int j = m; j >= 1; --j){
			if(a[i][j] == 1)
				ans.push_back({i - 1, {j, {i, j}}});
		}
	}
	for(int j = m; j >= 1; --j){
		if(a[1][j] == 1)
			ans.push_back({1, {j - 1, {1, j}}});
	}
	cout << ans.size() << '\n';
	for(auto k : ans)
		cout << k.F << ' ' << k.S.F << ' ' << k.S.S.F << ' ' << k.S.S.S << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
/*
1
3 3
110
111
000
*/
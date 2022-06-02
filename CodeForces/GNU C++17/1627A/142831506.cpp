#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL) 
#define ll long long
#define pb push_back
#define F first 
#define S second
using namespace std;
const int N = 1e3 + 5, MOD = 1e9 + 7;
int n, m, r, c;
char a[N][N];

void solve(){
	cin >> n >> m >> r >> c;
	bool ok = 0, okk = 0, okkk = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			cin >> a[i][j];
			if(i == r)
				if(a[i][j] == 'B') ok = 1;
			if(j == c)
				if(a[i][j] == 'B') okk = 1;
			if(a[i][j] == 'B') okkk = 1;
		}
	}
	if(a[r][c] == 'B'){
		cout << "0\n";
		return;
	}
	if(ok or okk){
		cout << "1\n";
		return;
	}
	if(okkk){
		cout << "2\n";
		return;
	}
	cout << "-1\n";
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    	solve();
	return 0;
}
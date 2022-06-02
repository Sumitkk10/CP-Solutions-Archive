#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
int n, m, a[N][9], l, r;

bool check(int cur){
	vector<int> msk((1 << m), -1);
	for(int i = 0; i < n; ++i){
		int ok = 0;
		for(int j = 0; j < m; ++j)
			if(a[i][j] >= cur)
				ok = (ok ^ (1LL << j));
		msk[ok] = i;
	}
	if(msk[(1 << m) - 1] != -1){
		l = r = msk[(1 << m) - 1];
		return true;
	}
	for(int i = 0; i < (1 << m); ++i){
		for(int j = i + 1; j < (1 << m); ++j){
			if(msk[i] != -1 and msk[j] != -1 and (i | j) == (1 << m) - 1){
				l = msk[i];
				r = msk[j];
				return true;
			}
		}
	}
	return false;
}

void solve(){
	cin >> n >> m;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			cin >> a[i][j];
	int low = 0, high = 1e9;
	while(low <= high){
		int mid = (low + high) / 2;
		if(check(mid))
			low = mid + 1;
		else
			high = mid - 1;
	}
	cout << l + 1 << ' ' << r + 1 << '\n';
}

int main() {
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
}
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define ll long long
#define F first 
#define S second
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	int a[n + 1];
	vector<int> pos[n + 1];
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		pos[a[i]].pb(i);
	}
	int cur = 1;
	vector<int> ans;
	while(cur <= n){
		int mx = cur, i;
		for(i = 0; i <= n; ++i){
			int low = 0, high = pos[i].size() - 1, ok = -1;
			while(low <= high){
				int mid = (low + high) / 2;
				if(pos[i][mid] >= cur){
					ok = mid;
					high = mid - 1;
				}
				else
					low = mid + 1;
			}
			if(ok == -1)
				break;
			mx = max(mx, pos[i][ok]);
		}
		ans.pb(i);
		cur = mx + 1;
	}
	cout << ans.size() << '\n';
	for(auto k : ans)
		cout << k << ' ';
	cout << '\n';
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
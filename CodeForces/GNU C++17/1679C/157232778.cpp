#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 1e6, MOD = 1e9 + 7;
long long n, cnt[N], cnt1[N];

void solve(){
	long long q;
	cin >> n >> q;
	set<int> row, col;
	for(int i = 1; i <= n; ++i){
		row.insert(i);
		col.insert(i);
	}
	while(q--){
		int t;
		cin >> t;
		if(t == 1){
			int x, y;
			cin >> x >> y;
			cnt[x]++;
			cnt1[y]++;
			auto k = row.find(x);
			if(k != row.end()) row.erase(k);
			k = col.find(y);
			if(k != col.end()) col.erase(k);
		}
		else if(t == 2){
			int x, y;
			cin >> x >> y;
			cnt[x]--;
			cnt1[y]--;
			if(cnt[x] == 0)
				row.insert(x);
			if(cnt1[y] == 0)
				col.insert(y);
		}
		else{
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			auto k = row.lower_bound(x1);
			if(k == row.end() or *k > x2){
				cout << "Yes\n";
				continue;
			}
			k = col.lower_bound(y1);
			if(k == col.end() or *k > y2){
				cout << "Yes\n";
				continue;
			}
			cout << "No\n";
		}
	}
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}
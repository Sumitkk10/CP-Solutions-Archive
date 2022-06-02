#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int n, k;
	cin >> n >> k;
	pair<int, int> points[n];
	for(int i = 0; i < n; ++i)
		cin >> points[i].first >> points[i].second;
	int ans = 0;
	for(int i = 0; i < n; ++i){
		int cnt = 0;
		for(int j = 0; j < n; ++j){
			long long int dis = abs(points[i].first - points[j].first) + abs(points[i].second - points[j].second);
			if(dis <= k){
				++cnt;
			}
		}
		ans=max(ans, cnt);
	}
	cout << (ans == n ? "1\n" : "-1\n");
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}

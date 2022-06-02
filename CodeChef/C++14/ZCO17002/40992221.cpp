#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
vector<pair<int, int> > balls[N];

void solve(){
	int n, m, w, b;
	cin >> n >> m >> w >> b;
	for(int i = 1; i <= n; ++i)
		balls[i].push_back({0, -1});
	for(int i = 0; i < w; ++i){
		int x, y;
		cin >> x >> y;
		balls[x].push_back({y, 0});
	}
	for(int i = 0; i < b; ++i){
		int x, y;
		cin >> x >> y;
		balls[x].push_back({y, 1});
	}
	long long int ans = 0;
	for(int i = 1; i <= n; ++i){
		bool ok = 0;
		sort(balls[i].begin(), balls[i].end());
		for(int j = 1; j < balls[i].size(); ++j){
			if(balls[i][j].first == m and balls[i][j].first == 1) 
				ok = 1;
			int which_ball = balls[i][j].second;
			if(which_ball == 1){ // black ball
				if(balls[i][j - 1].second == -1 or balls[i][j - 1].second == 1){ // black ball
					long long int from = balls[i][j - 1].first;
					++from;
					from = balls[i][j].first - from  + 1;
					ans += (from * (from + 1)) / 2;
					--ans;
				}
				else{ // white ball
					long long int from = balls[i][j - 2].first;
					++from;
					from = balls[i][j].first - from + 1;
					ans += ((from * (from + 1)) / 2);
					--ans;
					ans -= (balls[i][j].first - balls[i][j - 1].first + 1);
				}
			}
			else if(which_ball == 0){ // white ball
				if(j == 1 or balls[i][j - 1].second == 1) // coming from a black ball.
					continue;
				long long int from = balls[i][j - 2].first;
				++from;
				from = balls[i][j].first - from + 1;
				ans += (from * (from + 1)) / 2;
				from = balls[i][j - 1].first;
				from = balls[i][j].first - from + 1;
				ans -= (from * (from + 1)) / 2;
			}
		}
		if(!ok){
			if(balls[i][balls[i].size() - 1].second == -1 or balls[i][balls[i].size() - 1].second == 1){
				long long int from = balls[i][balls[i].size() - 1].first + 1;
				from = m - from + 1;
				ans += (from * (from + 1)) / 2;
				continue;
			}
			long long int from = balls[i][balls[i].size() - 2].first + 1;
			from = m - from + 1;
			ans += (from * (from + 1)) / 2;
			ans -= (m - balls[i][balls[i].size() - 1].first + 1);
		}
	}
	cout << ans << '\n';
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}

#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
using namespace std;
char a[1001][1001][5];
int n, m, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}, dis[1001][1001];

void dijk(){
	multiset<pair<int, pair<int, int> > > s;
	s.insert({0, {1, 1}});
	dis[1][1] = 0;
	while(!s.empty()){
		int i = (*s.begin()).second.first, j = (*s.begin()).second.second;
		int cost = (*s.begin()).first;
		s.erase(s.begin());
		for(int x = 0; x < 4; ++x){
			int cur_i = i + dx[x], cur_j = j + dy[x];
			if(cur_i < 1 or cur_j < 1 or cur_j > m or cur_i > n) continue;
			if(dy[x] == 1){
				int pos;
				char nxt = a[cur_i][cur_j][4];
				for(int k = 1; k <= 4; ++k){
					if(a[i][j][k] == nxt){
						pos = k;
						break;
					}
				}
				// if(i == 1 and j == 2) cout << cur_i << ' ' << cur_j << '\n';
				if(dis[cur_i][cur_j] > cost + (pos == 3 ? 3 : abs(pos - 2))){
					if(s.find({dis[cur_i][cur_j], {cur_i, cur_j}}) != s.end())
						s.erase(s.find({dis[cur_i][cur_j], {cur_i, cur_j}}));
					dis[cur_i][cur_j] = cost + (pos == 3 ? 3 : abs(pos - 2));
					s.insert({dis[cur_i][cur_j], {cur_i, cur_j}});
				}
			}
			else if(dx[x] == 1){
				int pos;
				char nxt = a[cur_i][cur_j][1];
				for(int k = 1; k <= 4; ++k){
					if(a[i][j][k] == nxt){
						pos = k;
						break;
					}
				}
				if(dis[cur_i][cur_j] > cost + (pos == 4 ? 3 : abs(pos - 3))){
					if(s.find({dis[cur_i][cur_j], {cur_i, cur_j}}) != s.end())
						s.erase(s.find({dis[cur_i][cur_j], {cur_i, cur_j}}));
					dis[cur_i][cur_j] = cost + (pos == 4 ? 3 : abs(pos - 3));
					s.insert({dis[cur_i][cur_j], {cur_i, cur_j}});
				}
			}
			else if(dy[x] == -1){
				int pos;
				char nxt = a[cur_i][cur_j][2];
				for(int k = 1; k <= 4; ++k){
					if(a[i][j][k] == nxt){
						pos = k;
						break;
					}
				}
				if(dis[cur_i][cur_j] > cost + (pos == 1 ? 3 : abs(4 - pos))){
					if(s.find({dis[cur_i][cur_j], {cur_i, cur_j}}) != s.end())
						s.erase(s.find({dis[cur_i][cur_j], {cur_i, cur_j}}));
					dis[cur_i][cur_j] = cost + (pos == 1 ? 3 : abs(4 - pos));
					s.insert({dis[cur_i][cur_j], {cur_i, cur_j}});
				}
			}
			else if(dx[x] == -1){
				int pos;
				char nxt = a[cur_i][cur_j][3];
				for(int k = 1; k <= 4; ++k){
					if(a[i][j][k] == nxt){
						pos = k;
						break;
					}
				}
				if(pos == 4){
					if(dis[cur_i][cur_j] > cost + 1){
						if(s.find({dis[cur_i][cur_j], {cur_i, cur_j}}) != s.end())
							s.erase(s.find({dis[cur_i][cur_j], {cur_i, cur_j}}));
						dis[cur_i][cur_j] = cost + 1;
						s.insert({dis[cur_i][cur_j], {cur_i, cur_j}});
					}
				}
				else if(pos == 3){
					if(dis[cur_i][cur_j] > cost + 2){
						if(s.find({dis[cur_i][cur_j], {cur_i, cur_j}}) != s.end())
							s.erase(s.find({dis[cur_i][cur_j], {cur_i, cur_j}}));
						dis[cur_i][cur_j] = cost + 2;
						s.insert({dis[cur_i][cur_j], {cur_i, cur_j}});
					}
				}
				else if(pos == 1){
					if(dis[cur_i][cur_j] > cost){
						if(s.find({dis[cur_i][cur_j], {cur_i, cur_j}}) != s.end())
							s.erase(s.find({dis[cur_i][cur_j], {cur_i, cur_j}}));
						dis[cur_i][cur_j] = cost;
						s.insert({dis[cur_i][cur_j], {cur_i, cur_j}});
					}
				}
				else{
					if(dis[cur_i][cur_j] > cost + 3){
						if(s.find({dis[cur_i][cur_j], {cur_i, cur_j}}) != s.end())
							s.erase(s.find({dis[cur_i][cur_j], {cur_i, cur_j}}));
						dis[cur_i][cur_j] = cost + 3;
						s.insert({dis[cur_i][cur_j], {cur_i, cur_j}});
					}
				}
			}
		}
	}
}

void solve(){
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			for(int k = 1; k <= 4; ++k)
				cin >> a[i][j][k];
			dis[i][j] = INT_MAX;
		}
	}
	dijk();
	cout << dis[n][m] << '\n';
}

int main() {
	fast;
	int t = 1;
 	// cin >> t;
	while(t--)
		solve();
	return 0;
}
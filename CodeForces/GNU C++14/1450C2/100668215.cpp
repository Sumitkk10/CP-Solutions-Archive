#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	string s[n];
	for(int i = 0; i < n; ++i)
		cin >> s[i];
	int cnt[3][2] = {{0, 0}, {0, 0}, {0, 0}}, k = 0; 
	// cnt[i][j] stores the number of cells of colour 0/1 in (i + j) % 3th cell.
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < s[i].size(); ++j){
			int rem = (i + j) % 3;
			if(s[i][j] == 'X'){
				cnt[rem][0]++;
				k++;
			}
			else if(s[i][j] == 'O'){
				cnt[rem][1]++;
				++k;
			}
		}
	}
	for(int rem = 0; rem < 3; ++rem){
		for(int rem1 = 0; rem1 < 3; ++rem1){
			if(rem == rem1) continue;
			if(cnt[rem][0] + cnt[rem1][1] <= k / 3){
				for(int i = 0; i < n; ++i){
					for(int j = 0; j < s[i].size(); ++j){
						int rem2 = (i + j) % 3;
						if(rem2 == rem and s[i][j] == 'X')
							s[i][j] = 'O';
						if(rem2 == rem1 and s[i][j] == 'O')
							s[i][j] = 'X';
					}
					cout << s[i] << '\n';
				}
				return;
			}
			if(cnt[rem][1] + cnt[rem1][0] <= k / 3){
				for(int i = 0; i < n; ++i){
					for(int j = 0; j < s[i].size(); ++j){
						int rem2 = (i + j) % 3;
						if(rem2 == rem and s[i][j] == 'O')
							s[i][j] = 'X';
						if(rem2 == rem1 and s[i][j] == 'X')
							s[i][j] = 'O';
					}
					cout << s[i] << '\n';
				}
				return;
			}
		}
	}
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();	
	return 0;
}

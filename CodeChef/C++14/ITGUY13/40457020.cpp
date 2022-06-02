#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int n, k;
	cin >> k >> n;
	int a[n];
	map<int, vector<int> > pos;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		pos[a[i]].push_back(i + 1);
	}
	if(pos[k].size() <= 1)
		cout << "-1\n";
	else
		cout << pos[k][0] << ' ' << pos[k][pos[k].size() - 1] << '\n';
}

int main(){
	fast;
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}

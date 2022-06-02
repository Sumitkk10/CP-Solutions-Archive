#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int n, tar, a[25];

void solve(){
	cin >> n >> tar;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < (1 << n); ++i){
		int sum = 0;
		for(int j = 0; j < n; ++j)
			if(i & (1 << j))
				sum += a[j];
		if(sum == tar){
			cout << "Yes\n";
			return;
		}
	}
	cout << "No\n";
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
// 
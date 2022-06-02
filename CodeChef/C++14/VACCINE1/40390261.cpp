#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int d1, v1, d2, v2;
	cin >> d1 >> v1 >> d2 >> v2;
	if(d1 > d2){
		swap(d1, d2);
		swap(v1, v2);
	}
	int p;
	cin >> p;
	int ans = 0, left1 = d2 - d1, cnt = 0;
	while(left1-- and ans < p){
		++cnt;
		ans += v1;
	}
	if(ans >= p){
		cout << cnt + d1 - 1 << '\n';
		return;
	}
	long long int left = p - ans;
	if(left % (v1 + v2) == 0)
		cout << cnt + (left / (v1 + v2)) + d1 - 1;
	else
		cout << cnt + (left / (v1 + v2)) + d1;
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
	return 0;
}
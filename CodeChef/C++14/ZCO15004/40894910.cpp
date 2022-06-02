#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	int n, Y = 501, X = 100001;
	cin >> n;
	int mn[X];
	for(int i = 0; i < X; ++i)
		mn[i] = 500;
	for(int i = 0; i < n; ++i){
		int x, y;
		cin >> x >> y;
		mn[x] = min(mn[x], y);
	}
	long long int ans = 0;
	for(int i = 1; i < Y; ++i){
		int largest = 0, cur = 0;
		for(int j = 1; j < X - 1; ++j){
			if(mn[j] >= i)
				cur++;
			else
				cur = 0;
			largest = max(largest, cur);
		}
		ans = max(ans, (long long int) i * (largest + 1));
	}
	cout << ans << '\n';
	return 0;
}

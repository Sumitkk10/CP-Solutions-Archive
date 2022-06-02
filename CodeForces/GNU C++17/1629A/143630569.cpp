#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define ll long long
#define F first 
#define S second
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;
int n, a[N];

void solve(){
	int n, k;
	cin >> n >> k;
	pair<int, int> a[n];
	for(int i = 0; i < n; ++i)
		cin >> a[i].F;
	for(int i = 0; i < n; ++i)
		cin >> a[i].S;
	sort(a, a + n);
	int cur = k;
	for(int i = 0; i < n; ++i){
		if(a[i].F <= cur)
			cur += a[i].S;
	}
	cout << cur << '\n';
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
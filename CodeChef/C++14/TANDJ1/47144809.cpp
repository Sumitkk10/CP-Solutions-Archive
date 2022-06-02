#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e7 + 5;

void solve(){
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    int ans  = abs(a - c) + abs(b - d);
    if(ans == k){
        cout << "YES\n";
        return;
    }
    if(ans < k and (k - ans) % 2 == 0){
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

int main() {
	fast;
	int t = 1;
    	cin >> t;
	while(t--)
		solve();
}
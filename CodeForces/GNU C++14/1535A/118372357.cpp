#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int a[4];
	for(int i = 0; i < 4; ++i)
		cin >> a[i];
	int one = max(a[0], a[1]), two = max(a[2], a[3]);
	sort(a, a + 4);
	if((one == a[3] and two == a[2]) or (one == a[2] and two == a[3])) 
		cout << "YES\n";
	else 
		cout << "NO\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
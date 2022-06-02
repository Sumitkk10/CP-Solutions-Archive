// not sure
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define ll long long
#define F first 
#define S second
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;
long long n, a[N];

void solve(){
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	long long chance = 0;
	for(int i = 0; i < n; ++i){
		if(chance == 0 and a[i] % 2){
			cout << "2\n";
			continue;
		}
		if(chance == 0){
			chance = 1;
			cout << "1\n";
			continue;
		}
		if(chance == 1 and a[i] % 2){
			cout << "1\n";
			continue;
		}
		chance = 0;
		cout << "2\n";
	}
}

int main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
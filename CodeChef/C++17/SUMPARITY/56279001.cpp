#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL) 
#define ll long long
#define pb push_back
#define F first 
#define S second
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;
int n, x;

void solve(){
	cin >> n >> x;
	if(x & 1){
		if(n & 1) cout << "Odd\n";
		else cout << "Even\n";
		return;
	}
	if(n == 1)
		cout << "Even\n";
	else
		cout << "Impossible\n";
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    	solve();
	return 0;
}
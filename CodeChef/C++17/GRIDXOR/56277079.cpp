#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL) 
#define ll long long
#define pb push_back
#define F first 
#define S second
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;
int n;

void solve(){
	cin >> n;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j)
			cout << "1 ";
		cout << '\n';
	}
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    	solve();
	return 0;
}
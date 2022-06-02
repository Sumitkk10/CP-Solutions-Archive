#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define F first
#define S second
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int x, y;
	cin >> x >> y;
	if((x + y) % 2){
		cout << "-1 -1\n";
		return;
	}
	long long req = (x + y) / 2;
	if(abs(req - x) + y == req){
		cout << req << ' ' << 0 << '\n';
		return;
	}
	cout << 0 << ' ' << req << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
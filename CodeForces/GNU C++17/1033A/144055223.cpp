#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;

void solve(){
	int n, x1, x2, x3, y1, y2, y3;
	cin >> n >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	if(x2 < x1 and y2 < y1){
		if(x3 < x1 and y3 < y1){
			cout << "YES\n";
			return;
		}
		cout << "NO\n";
		return;
	}
	if(x2 < x1 and y2 > y1){
		if(x3 < x1 and y3 > y1){
			cout << "YES\n";
			return;
		}
		cout << "NO\n";
		return;
	}
	if(x2 > x1 and y2 < y1){
		if(x3 > x1 and y3 < y1){
			cout << "YES\n";
			return;
		}
		cout << "NO\n";
		return;
	}
	if(x2 > x1 and y2 > y1){
		if(x3 > x1 and y3 > y1){
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
}
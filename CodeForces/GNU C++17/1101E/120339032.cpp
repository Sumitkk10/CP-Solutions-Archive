#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

void solve(){
	int n;
	cin >> n;
	int mx = 0, mx1 = 0;
	for(int i = 1; i <= n; ++i){
		char x;
		cin >> x;
		int a, b;
		cin >> a >> b;
		if(a > b)
			swap(a, b);
		if(x == '+'){
			mx = max(mx, a);
			mx1 = max(mx1, b);
		}
		else{
			if(mx <= a and mx1 <= b)
				cout << "YES\n";
			else if(mx <= b and mx1 <= a)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}
 
int main() {
	fast;
	int t = 1;
 	//  >> t;
	while(t--)
		solve();
	return 0;
}
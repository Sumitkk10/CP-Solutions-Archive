#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	int n;
	cin >> n;
	vector<pair<int, string> > in(n);
	for(int i = 0; i < n; ++i)
		cin >> in[i].first >> in[i].second;
	int x = 0;
	for(int i = 0; i < n; ++i){
		if(x == 0 and in[i].second != "South"){
			cout << "NO\n";
			return 0;
		}
		if(x == 20000 and in[i].second != "North"){
			cout << "NO\n";
			return 0;
		}
		if(in[i].second == "South")
			x += in[i].first;
		if(in[i].second == "North")
			x -= in[i].first;
		if(x < 0 or x > 20000){
			cout << "NO\n";
			return 0;
		}
	}
	cout << (x == 0 ? "YES\n" : "NO\n");
	return 0;
}

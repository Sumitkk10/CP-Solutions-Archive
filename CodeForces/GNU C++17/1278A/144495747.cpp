#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define ll long long
#define pii pair<long long, pair<int, int> >
#define F first 
#define S second
using namespace std;
const int N = 1e6 + 5;

void solve(){
	string a, b;
	cin >> a >> b;
	sort(a.begin(), a.end());
	for(int i = 0; i < b.size(); ++i){
		string temp;
		for(int j = i; j < i + a.size(); ++j){
			if(j > b.size()) break;
			temp.pb(b[j]);
		}
		sort(temp.begin(), temp.end());
		if(temp == a){
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
}
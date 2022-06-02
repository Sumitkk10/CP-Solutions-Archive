#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	map<int, vector<int> > pos;
	if(a == b){
		cout << "Yes\n";
		return;
	}
	for(int i = 0; i < a.size(); ++i){
		if(a[i] == b[i]) continue;
		if(a[i] != b[i] and a[i] == '0'){
			cout << "No\n";
			return;
		}
		bool ok = 0;
		for(int j = i + 1; j < n; ++j){
			if(a[j] != a[i] and b[j] != '0'){
				swap(a[j], a[i]);
				ok = 1;
				break;
			}
		}
		if(!ok){
			cout << "No\n";
			return;
		}
	}
	cout << "Yes\n";
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}

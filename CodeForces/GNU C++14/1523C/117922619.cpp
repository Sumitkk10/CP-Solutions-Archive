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
	int a[n];
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	vector<int> st;
	st.push_back(a[0]);
	cout << a[0] << '\n';
	for(int i = 1; i < n; ++i){
		if(a[i] == 1)
			st.push_back(a[i]);
		else{
			while(!st.empty()){
				int x = st.back();
				if(x + 1 != a[i])
					st.pop_back();
				else
					break;
			}
			if(st.size()) st.pop_back();
			st.push_back(a[i]);
		}
		int ct = 0;
		for(auto k : st){
			ct++;
			if(ct > 1) cout << ".";
			cout << k;
		}
		cout << '\n';
	}
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}

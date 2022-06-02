#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define int long long
using namespace std;
const int N = 1e6, MOD = 1e9 + 7;
int component[N];

int find(int x){
	while(true){
		if(x == component[x])
			return x;
		component[x] = component[component[x]];
		x = component[x];
	}
}

void merge(int a, int b){
	int u = find(a), v = find(b);
	component[u] = v;
}

void solve(){
	int n;
	cin >> n;
	vector<pair<int, pair<int, pair<int, int> > > > v;
	for(int i = 0; i < n; ++i){
		int l, r, c;
		cin >> c >> l >> r;
		v.pb({l, {r, {c, i}}});
		component[i] = i;
	}
	sort(v.begin(), v.end());
	set<pair<int, int> > red, blue;
	int ans = 0;
	// 0 --> red
	// 1 --> blue
	for(int i = 0; i < n; ++i){
		int l = v[i].F, r = v[i].S.F, c = v[i].S.S.F, pos = v[i].S.S.S;
		if(c == 0){
			while(!blue.empty() and (*blue.begin()).F < l)
				blue.erase(blue.begin());
			while(!blue.empty()){
				auto k = blue.begin();
				merge(pos, (*k).S);
		if(blue.size() == 1) break;
		blue.erase(k);
			}
			red.insert({r, pos});
		}
		else{
			while(!red.empty() and (*red.begin()).F < l)
				red.erase(red.begin());
			while(!red.empty()){
				auto k = red.begin();
				merge(pos, (*k).S);
                                if(red.size() == 1) break;
				red.erase(k);
			}
			blue.insert({r, pos});
		}
	}
	set<int> s;
	for(int i = 0; i < n; ++i){
		int x = find(i);
		s.insert(x);
	}
	cout << s.size() << '\n';
}

int32_t main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
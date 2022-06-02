
// WRONG ANSWER!!

#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define ll long long
#define F first 
#define S second
using namespace std;
const int N = 2e5 + 5, MOD = 1e9 + 7;
int n, a[N];

void solve(){
	cin >> n;
	set<pair<int, int> > s;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		s.insert({a[i], i});
	}
	int chance = 0, pre = -1;
	while(true){
		if(s.empty())
			break;
		pair<int, int> cur = *s.rbegin();
		auto k = s.find(cur);
		if(cur.S == pre){
			s.erase(k);
			if(s.empty()){
				cout << (chance == 0 ? "HL\n" : "T\n");
				return;
			}
			pair<int, int> curr = *s.rbegin();
			auto kk = s.find(curr);
			s.erase(kk);
			if(curr.F != 1)
				s.insert({curr.F - 1, curr.S});
			pre = curr.S;
			s.insert(cur);
		}
		else{
			s.erase(k);
			if(cur.F != 1)
				s.insert({cur.F - 1, cur.S});
			pre = cur.S;
		}
		chance ^= 1;
	}
	cout << (chance == 0 ? "HL\n" : "T\n");
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

bool is_possible(string s){
	int cnt = 0;
	for(auto k : s){
		if(k == '(')
			++cnt;
		else
			--cnt;
		if(cnt < 0)
			return false;
	}
	if(cnt) return false;
	return true;
}

void solve(){
	string s;
	cin >> s;
	string a = s, b = s, c = s, d = s, e = s, f = s;
	for(int i = 0; i < a.size(); ++i){
		if(a[i] == 'A')
			a[i] = '(';
		else
			a[i] = ')';
		if(b[i] == 'B')
			b[i] = '(';
		else
			b[i] = ')';
		if(c[i] == 'C')
			c[i] = '(';
		else
			c[i] = ')';
		if(d[i] == 'A')
			d[i] = ')';
		else
			d[i] = '(';
		if(e[i] == 'B')
			e[i] = ')';
		else
			e[i] = '(';
		if(f[i] == 'C')
			f[i] = ')';
		else
			f[i] = '(';
	}
	if(is_possible(a) or is_possible(b) or is_possible(c) or is_possible(d) or is_possible(e) or is_possible(f))
		cout << "YES\n";
	else
		cout << "NO\n";
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e7 + 5;

void solve(){
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    long long cost = 0;
    for(int i = 1; i < s.size(); ++i){
        if(s[i] == s[i - 1]) cost += 2;
        else cost++;
    }
    while(q--){
        int pos;
        cin >> pos;
        --pos;
        if(pos != 0 and pos != s.size() - 1){
            if(s[pos - 1] == s[pos]) cost -= 2;
            else cost--;
            if(s[pos + 1] == s[pos]) cost -= 2;
            else cost--;
            s[pos] = (s[pos] == '0' ? '1' : '0');
            if(s[pos - 1] == s[pos]) cost += 2;
            else cost++;
            if(s[pos + 1] == s[pos]) cost += 2;
            else cost++;
        }
        else if(pos == 0){
            if(s[pos + 1] == s[pos]) cost -= 2;
            else cost--;
            s[pos] = (s[pos] == '0' ? '1' : '0');
            if(s[pos + 1] == s[pos]) cost += 2;
            else cost++;
        }
        else{
            if(s[pos - 1] == s[pos]) cost -= 2;
            else cost--;
            s[pos] = (s[pos] == '0' ? '1' : '0');
            if(s[pos - 1] == s[pos]) cost += 2;
            else cost++;
        }
        cout << cost << '\n';
    }
}

int main() {
	fast;
	int t = 1;
     cin >> t;
	while(t--)
		solve();
}
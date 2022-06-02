#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    string s, t;
    cin >> s >> t;
    s = " " + s;
    string seg[s.size() + 3][s.size() + 3];
    for(int i = 1; i <= s.size(); ++i){
        string cur;
        for(int j = i; j <= s.size(); ++j){
            cur.push_back(s[j]);
            string temp = cur;
            temp.pop_back();
            reverse(temp.begin(), temp.end());
            seg[j][i] = temp;
            seg[i][j] = cur;
        }
    }
    for(int i = 1; i <= s.size(); ++i){
        for(int k = 0; k < s.size() - i + 1; ++k){
            string cur;
            if((t.size() - k - 1) >= (i + k)) continue;
            if(t.size() - k - 1 <= 0) cur = seg[i][i + k];
            else cur = seg[i][i + k] + seg[i + k][i + k - max(0, (int) (t.size() - (k + 1)))];
            if(cur == t){
                cout << "YES\n";
                return;
            }
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
    return 0;
}
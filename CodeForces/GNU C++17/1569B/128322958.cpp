#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n, ct = 0;
    cin >> n;
    string s;
    cin >> s;
    char ans[n + 1][n + 1];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            ans[i][j] = '#';
        }
        ans[i][i] = 'X';
    }
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == '1'){
            for(int j = 0; j < s.size(); ++j){
                if(ans[i][j] != '#') continue;
                ans[i][j] = '=';
                if(i == j) ans[i][i] = 'X';
            }
        }
        else{
            ++ct;
            bool cnt = 0;
            for(int j = 0; j < s.size(); ++j){
                if(ans[i][j] == '+')
                    cnt = 1;
            }
            for(int j = 0; j < s.size(); ++j){
                if(ans[i][j] != '#') continue;
                if(s[j] == '2' and !cnt){
                    ans[i][j] = '+';
                    ans[j][i] = '-';
                    cnt = 1;
                }
                else if(s[j] == '2' and cnt){
                    ans[i][j] = '-';
                    ans[j][i] = '+';
                }
                else{
                    ans[i][j] = '=';
                    ans[j][i] = '=';
                }
            }
        }
    }
    for(int i = 0; i < s.size(); ++i){
        int ok = 0, ok1 = 0;
        for(int j = 0; j < n; ++j){
            if(ans[i][j] == '+') ++ok;
            if(ans[i][j] == '-') ++ok1;
        }
        if(s[i] == '1' and ok1) ct = 1;
        if(s[i] == '2' and !ok) ct = 1;
    }
    if(ct == 1){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j)
            cout << ans[i][j];
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
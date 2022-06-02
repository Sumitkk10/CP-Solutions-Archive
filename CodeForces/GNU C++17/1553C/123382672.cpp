#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int check(string s){
    int ct = 0, ct1 = 0;
    for(int i = 0; i < s.size(); ++i){
        if(i % 2 == 0 and s[i] != '0') ++ct;
        if(i % 2 == 1 and s[i] == '1') ++ct1;
        int ctt = 0, ctt1 = 0;
        for(int j = i + 1; j < s.size(); ++j){
            if(j % 2 == 0 and s[j] == '1') ++ctt;
            if(j % 2) ++ctt1;
        }
        if(ct > ct1 + ctt1){
            return (i + 1);
        }
    }
    return s.size();
}

int check1(string s){
    int ct = 0, ct1 = 0;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == '1' and i % 2 == 0) ++ct;
        if(i % 2 and s[i] != '0')++ct1;
        int ctt = 0, ctt1 = 0;
        for(int j = i + 1; j < s.size(); ++j){
            if(j % 2 == 0) ++ctt;
            else if(s[j] == '1')++ctt1;
        }
        if(ct1 > ctt + ct)
            return (i + 1);
    }
    return s.size();
}

void solve(){
    string s;
    cin >> s;
    cout << min(check(s), check1(s)) << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
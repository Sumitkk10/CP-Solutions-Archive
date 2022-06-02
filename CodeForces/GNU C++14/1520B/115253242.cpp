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
    if(n <= 9){
        cout << n << '\n';
        return;
    }
    string s = to_string(n), k = to_string(n), wtf;
    k[0] = '1';
    wtf.push_back('1');
    for(int i = 1; i < s.size(); ++i){
        s[i] = s[0];
        k[i] = '1';
        if(i != s.size() - 1)
            wtf.push_back('1');
    }
    wtf[wtf.size() - 1] = '2';
    long long x = stoll(s), ok = 0, rem = stoll(k);
    if(x <= n) ++ok;
    x -= rem;
    string wut = to_string(x), wutt = to_string(rem);
    if(wut.size() != wutt.size()){
        x += rem;
        x -= stoll(wtf);
        if(wtf.size()) wtf.pop_back();
        if(wtf.size()) wtf.pop_back();
        wtf.push_back('2');
        rem /= 10;
    }
    while(x >= 1){        
        ++ok;
        x -= rem;
        string wut = to_string(x), wutt = to_string(rem);
        if(wut.size() != wutt.size()){
            x += rem;
            x -= stoll(wtf);
            if(wtf.size()) wtf.pop_back();
            if(wtf.size()) wtf.pop_back();
            wtf.push_back('2');
            rem /= 10;
        }
    }
    cout << ok << '\n';
}

int main(){
    fast;
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}

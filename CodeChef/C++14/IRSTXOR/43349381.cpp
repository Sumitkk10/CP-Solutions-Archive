#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    long long c;
    cin >> c;
    string s;
    while(c){
        s.push_back((c % 2) + '0');
        c /= 2;
    }
    reverse(s.begin(), s.end());
    long long a = 0, b = 0;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == '0'){
            a += (1LL << (s.size() - i - 1));
            b += (1LL << (s.size() - i - 1));
        }
        else{
            if(a <= b)
                a += (1LL << (s.size() - i - 1));
            else
                b += (1LL << (s.size() - i - 1));
        }
    }
    cout << a * b << "\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}

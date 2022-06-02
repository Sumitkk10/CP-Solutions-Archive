#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

string dec_to_bin(long long x){
    string s;
    if(x == 0){
        s = "0";
        return s;
        
    }
    while(x > 1){
        s.push_back((x % 2 ? '1' : '0'));
        x /= 2;
    }
    s.push_back('1');
    reverse(s.begin(), s.end());
    return s;
}

long long int bin_to_dec(string s){
    long long ans = 0, base = 1;
    for(int i = s.size() - 1; i >= 0; --i){
        if(s[i] == '1')
            ans += base;
        base = base * 2;
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    long long int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    if(n == 1){
        cout << "0\n";
        return;
    }
    vector<long long int> ans;
    ans.push_back(0);
    for(int i = 2; i <= n; ++i){
        string x = dec_to_bin(a[i - 1]);
        string y = dec_to_bin(a[i]);
        while(x.size() < y.size())
            x = '0' + x;
        while(y.size() < x.size())
            y = '0' + y;
        string cur;
        for(int i = 0; i < x.size(); ++i){
            if(x[i] == '1' and y[i] == '0') cur.push_back('1');
            else cur.push_back('0');
        }
        long long ok = bin_to_dec(cur);
        ans.push_back(ok);
        a[i] = a[i] ^ ok;
    }
    for(long long k : ans)
        cout << k << ' ';
    cout << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}

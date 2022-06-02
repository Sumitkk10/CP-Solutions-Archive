#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

string to_bin(int x){
    string s;
    while(x > 1){
        if(x % 2 == 0)
            s.push_back('0');
        else
            s.push_back('1');
        x /= 2;
    }
    s.push_back('1');
    reverse(s.begin(), s.end());
    return s;
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &val : a)
        cin >> val;
    vector<string> ans;
    for(int i = 0; i < n; ++i){
        string s = to_bin(a[i]);
        ans.push_back(s);
    }
    vector<int> ok;
    for(int i = 0; i < ans.size(); ++i){
        if(ans[i][ans[i].size() - 1] == '0') ok.push_back(i);
    }
    for(int i = 0; i < ans.size(); ++i){
        if(ans[i][ans[i].size() - 1] == '1') ok.push_back(i);
    }
    for(auto k : ok)
        cout << a[k] << ' ';
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

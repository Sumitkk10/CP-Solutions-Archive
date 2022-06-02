#include <bits/stdc++.h>
using namespace std;
const long long N = 1e18;
vector<long long> v;

int calc(string t, string s){
    while(t.size() < s.size())
        t.push_back('#');
    int ok = 0;
    while(s.size() < t.size()){
        s.push_back('#');
        ++ok;
    }
    int j = 0, i = 0, ans = 0;
    while(i < t.size() and j < s.size()){
        if(t[i] != s[j]){
            if(t[i] != '#') ++ans;
            ++i;
        }
        else{
            ++i;
            ++j;
        }
    }
    ans += s.size() - j - ok;
    return ans;
}

void solve(){
    string s;
    cin >> s;
    int ans = INT_MAX;
    for(int i = 0; i < v.size(); ++i){
        string temp = s, cur = to_string(v[i]);
        ans = min(ans, calc(temp, cur));
    }
    cout << ans << "\n";
}

int main() {
    for(long long i = 1; i <= N; i *= 2)
        v.push_back(i);
    int t;
    cin >> t;
    while(t--)
        solve();
	return 0;
}

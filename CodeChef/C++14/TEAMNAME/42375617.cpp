#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7;
const int N = 50003 + 2;

void solve() {
    int n;
    cin >> n;
    string s[n];
    map<string, bool> is_present;
    map<char, bool> present;
    for(int i = 0; i < n; ++i) {
        cin >> s[i];
        is_present[s[i]] = true;
        present[s[i][0] - 'a'] = true;
    }
    int suff_sum[n + 1][26][26];
    memset(suff_sum, 0, sizeof suff_sum);
    for(int i = n - 1; i >= 0; --i){
        for(int j = 0; j < 26; ++j)
            for(int k = 0; k < 26; ++k)
                suff_sum[i][j][k] = suff_sum[i + 1][j][k];
        for(int j = 0; j < 26; ++j){
            string ok = s[i];
            ok[0] = (j + 'a');
            if(!is_present[ok])
                suff_sum[i][s[i][0] - 'a'][j]++;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 26; ++j){
            if(!present[j] or (s[i][0] - 'a') == j)
                continue;
            string ok = s[i];
            ok[0] = (j + 'a');
            if(is_present[ok])
                continue;
            ans += 2 * suff_sum[i + 1][j][s[i][0] - 'a'];
        }
    }
    cout << ans << "\n";
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
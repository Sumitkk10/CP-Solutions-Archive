#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
const long long int N = 1e6 + 5;

void solve(){
    int n;
    cin >> n;
    multiset<int> s;
    while(n--){
        int x;
        cin >> x;
        if(s.find(x) == s.end()) s.insert(x);
        else s.erase(s.find(x));
    }
    cout << s.size() << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    cout.tie(NULL);
    int t = 1;
    while(t--)
        solve();
    return 0;
}
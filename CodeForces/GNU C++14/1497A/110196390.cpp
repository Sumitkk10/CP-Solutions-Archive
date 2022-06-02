#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
using namespace std;
const int N = 5e3 + 5;

void solve(){
    int n;
    cin >> n;
    int a[n];
    multiset<int> s;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        s.insert(a[i]);
    }
    int cur = 0;
    while(!s.empty()){
        if(s.find(cur) != s.end()){
            cout << cur << ' ';
            s.erase(s.find(cur));
        }
        else{
            cout << *s.rbegin() << ' ';
            s.erase(s.find(*s.rbegin()));
        }
        ++cur;
    }
    cout << "\n";
}

int main() {
    fast;
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
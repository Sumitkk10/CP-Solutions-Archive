#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;


int main(){
    fast;
    int n;
    cin >> n;
    pair<int, int> a[n];
    for(int i = 0; i < n; ++i){
        int x, y;
        cin >> x >> y;
        a[i].first = min(x, y);
        a[i].second = max(x, y);
    }
    sort(a, a + n);
    int ans = 1, ct = 2;
    for(int i = 1; i < n; ++i){
        if(a[i].first >= ct) {
            ++ans;
            ++ct;
        }
    }
    cout << ans << '\n';
    return 0;
}
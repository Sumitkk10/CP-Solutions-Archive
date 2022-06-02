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
        cin >> a[i].second >> a[i].first;
        a[i].first += a[i].second;
    }
    sort(a, a + n);
    int ans = 1, pre = a[0].first;
    for(int i = 1; i < n; ++i){
        if(a[i].second > pre) {
            ++ans;
            pre = a[i].first;
        }
    }
    cout << ans << '\n';
    return 0;
}
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
using namespace std;
const int N = 1000 + 5;
const int MOD = 1e9 + 7;

int main() {
    fast;
    int n;
    cin >> n;
    pair<int, int> a[n], b[n];
    for(int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    for(int i = 0; i < n; ++i) {
        cin >> b[i].first;
        b[i].second = i + 1;
    }
    sort(a, a + n);
    sort(b, b + n);
    int ct = 0, ct1 = 1;
    vector<int> ans(n + 5, 0);
    for(int i = 0; i < n; ++i){
        int low = ct, high = n - ct1, ok = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(b[mid].first < a[i].first){
                ok = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        if(ok == -1){
            ans[a[i].second] = b[n - ct1].second;
            ++ct1;
        }
        else{
            ans[a[i].second] = b[ok].second;
            ++ct;
        }
    }
    cout << ct << '\n';
    for(int i = 1; i <= n; ++i)
        cout << ans[i] << '\n';
    cout << '\n';
    return 0;
}

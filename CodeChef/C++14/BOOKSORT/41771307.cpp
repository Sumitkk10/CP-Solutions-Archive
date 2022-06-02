#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
using namespace std;
const int N = 1000 + 5;
const int MOD = 1e9 + 7;

int main() {
    fast;
    long long int n;
    cin >> n;
    vector<long long int> a(n), lis;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    lis.push_back(a[0]);
    for(int i = 1; i < n; ++i){
        if(a[i] >= lis.back())
            lis.push_back(a[i]);
        else {
            int low = 0, high = lis.size() - 1, ok = -1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (lis[mid] >= a[i]) {
                    ok = mid;
                    high = mid - 1;
                }
                else
                    low = mid + 1;
            }
            if (ok != -1)
                lis[ok] = a[i];
        }
    }
    cout << n - lis.size();
    return 0;
}

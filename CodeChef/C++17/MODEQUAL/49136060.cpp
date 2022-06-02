#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
using namespace std;

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        long long a[n + 1], cnt = 0, res = 0, mn = INT_MAX;
        bool ban = 0;
        set<long long> s;
        for(int i = 1; i <= n; ++i){
            cin >> a[i];
            if(a[i] == 0){
                ban = 1;
                ++cnt;
            }
            s.insert(a[i]);
            mn = min(mn, a[i]);
        }
        if(ban){
            cout << (n - cnt) << "\n";
            continue;
        }
        if(s.size() == 1){
            cout << "0\n";
            continue;
        }
        ban = true;
        for(int i = 1; i <= n; ++i){
            if(a[i] == mn) continue;
            if((a[i] % (a[i] - mn)) != mn)
                ban = false;
            ++res;
        }
        if(ban)
            cout << res << "\n";
        else
            cout << n << "\n";
    }
    return 0;
}
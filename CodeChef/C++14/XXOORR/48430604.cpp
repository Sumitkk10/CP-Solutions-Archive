#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        long long a[n + 1];
        for(int i = 1; i <= n; ++i)
            cin >> a[i];
        map<int, int> bits;
        for(int i = 1; i <= n; ++i){
            long long x = a[i];
            if(x <= 0) continue;
            string s;
            while(x > 1){
                if(x % 2) s.push_back('1');
                else s.push_back('0');
                x /= 2;
            }
            s.push_back('1');
            reverse(s.begin(), s.end());
            int pos = 0;
            for(int j = s.size() - 1; j >= 0; --j){
                if(s[j] == '1')
                    bits[pos]++;
                ++pos;
            }
        }
        long long int ans = 0;
        for(int i = 0; i < 64; ++i){
            // cout << bits[i] << ' ';
            ans += (bits[i] + k - 1) / k;
        }
        cout << ans << '\n';
    }
    return 0;
}
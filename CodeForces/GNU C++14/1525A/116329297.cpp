#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int req = 100 - n;
        if(req == 0 or n == 0){
            cout << "1\n";
            continue;
        }
        long long res = INT_MAX;
        for(int i = 1; i <= 100; ++i){
            for(int j = 1; j <= 100; ++j){
                long long qq = i + j;
                long long yay = n * qq, yayy = (n - 100) * qq;
                if(yay % 100 == 0 and yayy % 100 == 0)
                    res = min(qq, res);
            }
        }
        cout << res << '\n';
    }
    return 0;
}

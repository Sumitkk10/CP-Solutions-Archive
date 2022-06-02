#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1003;

int main(){
    fast;
    ll t; 
    cin >> t;
    while(t--){
        ll n, niket = 0;
        cin >> n;
        char a[N][N];
        memset(a, -1, N);
        for(int i = 1; i <= n; ++i) 
            for(int j = 1; j <= n; ++j) 
                cin >> a[i][j];
        for(int i = 1; i <= n; ++i){
            int j = 1, k = i;
            while(true){
                if(a[j][k] == 'L')
                    --k;
                else if(a[j][k] == 'R') ++k;
                else ++j;
                if(j < 1){ 
                    ++j;
                    break;
                }
                if(k < 1){ 
                    ++k;
                    break;
                }
                if(j > n){ 
                    --j;
                    break;
                }
                if(k > n){ 
                    --k;
                    break;
                }
            }
            if((j + k) % 2 == 0) niket++;
        }
        cout << niket << "\n";
    }
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}
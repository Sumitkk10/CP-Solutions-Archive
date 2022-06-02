#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const ll MOD = 1e9 + 7;

int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll k;
        cin >> k;
        char ans[8][8];
        for(int i = 0; i < 8; ++i)
            for(int j = 0; j < 8; ++j)
                ans[i][j] = 'X';
        ans[0][0] = 'O';
        int i = 0, j = 1;
        --k;
        while(k--){
            ans[i][j] = '.';
            if(j == 7){
                j = -1;
                ++i;
            }
            ++j;
        }
        for(i = 0; i < 8; ++i){
            for(j = 0; j < 8; ++j){
                cout << ans[i][j];
            }
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void printDiamond(int n){
    int space = n - 1;
    for (int i = 0; i < n; i++){
        for (int j = 0;j < space; j++)
            cout << " ";
        for (int j = 0; j <= i; j++)
            cout << "I ";
        cout << endl;
        space--;
    }
    space = 0;
    for (int i = n; i > 0; i--){
        for (int j = 0; j < space; j++)
            cout << " ";
        for (int j = 0;j < i;j++)
            cout << "I ";
        cout << endl;
        space++;
    }
}
 
void solve(){
    int n;
    cin >> n;
    printDiamond(n);
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
    // you should actually read the stuff at the bottom
}
/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
    * Read other problems if stuck on this one.
*/

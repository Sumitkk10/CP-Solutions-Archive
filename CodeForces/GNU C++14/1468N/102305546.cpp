#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
 
void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    int in[5];
    for(int i = 0; i < 5; ++i)
        cin >> in[i];
    if(in[0] > a or in[1] > b or in[2] > c){
        cout << "NO\n";
        return;
    }
    a -= in[0];
    b -= in[1];
    c -= in[2];
    if(in[3] > (a + c)){
        cout << "NO\n";
        return;
    }
    if(in[3] < a){
        a = 0;
        if(in[4] > (b + c)){
            cout << "NO\n";
            return;
        }
    }
    else{
        in[3] -= a;
        c -= in[3];
        if(in[4] > (b + c)){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
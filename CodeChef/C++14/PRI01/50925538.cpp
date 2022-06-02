#include <iostream>
#include<vector>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
using namespace std;
vector<int> a = {0, 0, 0}, b = {0, 0, 0, 0}, fibo = {0, 1};

void solve(){
    int n;
    cin >> n;
    int num1 = 0, num2 = 0, c = 0, p = 0;
    for (int i = 0; i <= 41; i++){
        if(b[i] == n){
            c = 1;
            p = i + 1;
            break;
        }
        if(b[i] > n){
            num1 = i - 1;
            num2 = i;
            break;
        }
    }
    int ans;
    if(c)
        ans = fibo[p] - 1;
    else
        ans = n - b[num1] + fibo[num2];
    cout << ans << endl;
}

int main(){
    fast;
    for (int i = 2; i <= 43; i++){
        int cur = fibo[i - 2] + fibo[i - 1];
        fibo.push_back(cur);
    }
    for (int i = 3; i <= 42; i++){
        int cur = fibo[i + 1] - fibo[i] - 1;
        a.push_back(cur);
    }
    for (int i = 4; i <= 41; i++){
        int cur = b[i - 1] + a[i];
        b.push_back(cur);
    }
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}

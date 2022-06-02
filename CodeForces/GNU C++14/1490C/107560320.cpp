#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int N = 1e6 + 5;

bool perfectCube(long long int N)
{
    long long int cube_root;
    cube_root = round(cbrt(N));
    if (cube_root * cube_root * cube_root == N)
        return true;
    return false;
}

int main() {
	fast;
	int t;
	cin >> t;
	while(t--){
	    long long n;
	    cin >> n;
	    bool ok = 0;
	    for(long long int i = 1; i*i <= n; ++i){
	        long long x = i*i*i;
	        long long left = n - x;
	        if(left == 0 or left < 0)
	            break;
	        if(perfectCube(left)){
	            cout << "YES\n";
	            ok = 1;
	            break;
	        }
	    }
	    if(!ok)
	        cout << "NO\n";
	}
	return 0;
}

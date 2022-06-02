/*
 https://www.codechef.com/viewsolution/53093224
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void run()
{
    int N, K;
    cin >> N >> K;

    string S;
    cin >> S;

    string res(N, '0');
    vector<int> T;

    for(int i = 0; i < N; i++)
    {
        if(T.size() == 0 || S[i] == S[T.back()]) T.push_back(i);
        else T.pop_back();
    }

    res[0] = '1';
    for(int i = K; i < T.size(); i += K) res[T[i]] = '1';

    cout << res << '\n';
}

int main()
{
    int t;
    cin >> t;
    while(t--) run();
}
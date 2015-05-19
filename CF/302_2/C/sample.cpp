#include <iostream>
using namespace std;

int n, m, b;
long long mod;

long long a[505];

long long dp[2][505][505];

int main () {

    cin >> n >> m >> b >> mod;

    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }

    for (int i=1; i<=n; i++) dp[i % 2][0][0] = 1L;

    for (int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            for (int k=0; k<=b; k++) {
                if (k < a[i]) dp[i % 2][j][k] = dp[(i-1) % 2][j][k] % mod;
                else dp[i % 2][j][k] = (dp[i % 2][j-1][k - a[i]] + dp[(i-1) % 2][j][k]) % mod;
            }
        }
    }

    long long ans = 0;

    for (int i=0; i<=b; i++) {
        ans = (ans + dp[n % 2][m][i]) % mod;
    }

    cout << ans % mod << endl;

    return 0;
}

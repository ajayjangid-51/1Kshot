#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pint unsigned int
#define pb push_back
#define vb vector<bool>
#define vi vector<int>
#define vs vector<string>
#define vvi vector<vi>
#define vvb vector<vb>
#define pii pair<int, int>
#define endl "\n"
#define nline cout << "\n"
#define print(x) cout << x << " "
#define size(x) x.size()
#define trav(a) for (auto x : a)
#define trav2(a) for (auto y : a)
#define range(arr) arr.begin(), arr.end()
#define leftpoint "👈"
#define rightpoint "👉"
#define downpoint "👇"
#define uppoint "👆"
#define fire "🔥"
#define star "⭐"
#define smile "😃"
#define smile2 "👺"
#define debline(x) cout << "👉Line-" << __LINE__ << ": " << #x << " = " << x << endl
#define linebreak2(x) cout << "🟢" << #x << " = " << x << "________________🟢 " << endl
#define all(x) x.begin() x.end()
#define deb(x) cout << #x << "= " << x << "\n"
#define deb2(a, b) cout << #a << "= " << a << " | " << #b << "= " << b << "\n"
#define deb3(a, b, c) cout << #a << "= " << a << " | " << #b << "= " << b << " | " << #c << "=" << c << "\n"
#define debpair(pair) cout << #pair << ".first = " << pair.first << " " << #pair << ".second = " << pair.second << endl
#define linebreak1 cout << "_______________________________" \
                        << "\n"                              \
                           "\n"
#define forn(i, start, n) for (auto i = start; i < n; i++)
#define io_faster                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

const int MOD = 1000000007;
double PI = 4 * atan(1);

void file()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int countNeighbours(vvi &A, int i, int j, int m, int n)
{
    int cnt = 0;
    for (int i1 = max(i - 1, 0); i1 <= min(i + 1, m - 1); i1++)
    {
        for (int j1 = max(j - 1, 0); j1 <= min(j + 1, n - 1); j1++)
        {
            cnt += ((A[i1][j1]) & 1);
            // deb2(i1, j1);
        }
    }
    cnt -= A[i][j] & 1;
    // deb(cnt);
    return cnt;
}
void solve()
{
    vvi A = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
    int m = size(A);
    int n = size(A[0]);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int livenbrs = countNeighbours(A, i, j, m, n);
            // int livenbrs = 0;
            if (A[i][j] == 0 and livenbrs == 3)
            {
                A[i][j] = 2;
            }
            else if (A[i][j] == 1 and (livenbrs == 2 or livenbrs == 3))
            {
                A[i][j] = 3;
            }
        }
    }
    print("heii");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i][j] >>= 1;
        }
    }

    linebreak1;
    trav(A)
    {
        trav2(x) print(y);
        nline;
    }
    linebreak1;
}

int main()
{
    io_faster
    file();
    int t = 1;
    //	cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
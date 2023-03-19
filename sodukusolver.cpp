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
#define siz(x) x.size()
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
#define linebreak1 cout << "\n"                              \
                        << "_______________________________" \
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

bool isokay(int k, int row, int col, vvi &v)
{
    for (int i = 0; i < 9; i++)
    {
        if (v[row][i] != 0 and v[row][i] == k)
            return 0;
        if (v[i][col] != 0 and v[i][col] == k)
            return 0;
        if (v[(row / 3) * 3 + (i / 3)][(col / 3) * 3 + (i % 3)] != 0 and v[(row / 3) * 3 + (i / 3)][(col / 3) * 3 + (i % 3)] == k)
        {
            return 0;
        }
    }
    return 1;
}

bool fn(vvi &v)
{
    for (int i = 0; i < siz(v); i++)
    {
        for (int j = 0; j < siz(v[0]); j++)
        {
            if (v[i][j] == 0)
            {

                for (int k = 1; k <= 9; k++)
                {

                    if (isokay(k, i, j, v))
                    {
                        v[i][j] = k;
                        if (fn(v))
                            return 1;
                        else
                            v[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solve()
{
    vvi v = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    fn(v);

    print("hello");

    linebreak1;
    trav(v)
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
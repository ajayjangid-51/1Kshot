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

void solve()
{
    int n;
    cin >> n;
    vvi v(n, vi(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
    vvi v2 = v;
    vi back_row(n, -1);
    back_row[0] = v[0][0];
    for (int i = 1; i < n; i++)
    {
        if (v[0][i] != -1 and back_row[i - 1] != -1)
        {
            back_row[i] = v[0][i] + back_row[i - 1];
            v[0][i] = 0;
        }
    }
    linebreak1;
    trav(back_row) print(x);
    linebreak1;
    for (int i = 1; i < n; i++)
    {
        vi curr_row(n, -1);
        // vi curr_col(n);
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] != -1)

                if (j - 1 >= 0)
                {
                    int max1 = INT_MIN;
                    if (back_row[j] != -1)
                        max1 = back_row[j];
                    int max2 = INT_MIN;
                    if (curr_row[j - 1] != -1)
                        max2 = curr_row[j - 1];

                    int maxi = max(max1, max2);
                    if (maxi == max1 and max1 != INT_MIN)
                    {
                        curr_row[j] = maxi + v[i][j];
                        v[i - 1][j] = 0;
                        // v[i][j - 1] = curr_row[j - 1];
                        v[i][j - 1] = v2[i][j - 1];

                        // curr_col[j] = maxi;
                    }
                    else if (max2 != INT_MIN)
                    {
                        curr_row[j] = maxi + v[i][j];
                        v[i][j - 1] = 0;
                        // v[i - 1][j] = back_row[j];
                        v[i - 1][j] = v2[i - 1][j];
                        // curr_col[j] = maxi;
                    }
                }
                else
                {
                    if (v[i][0] != -1 and back_row[j] != -1)
                    {
                        curr_row[0] = v[i][0] + back_row[0];
                        v[i - 1][0] = 0;
                    }
                }
        }
        // print(smile2);
        print("🥊");
        trav(curr_row) print(x);
        linebreak1;
        back_row = curr_row;
        // back_col = curr_col;
    }

    v[n - 1][n - 1] = 0;

    linebreak1;
    debline(back_row[n - 1]);
    // debline(back_col[n - 1]);
    linebreak1;
    trav(v)
    {
        trav2(x) print(y);
        nline;
    }
    linebreak1;
    // now go from [n-1][n-1] to back again to [0][0].
    // back_row.assign()
    back_row.assign(n, -1);
    back_row[n - 1] = v[n - 1][n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (v[0][i] != -1 and back_row[i + 1] != -1)
        {
            back_row[i] = v[n - 1][i] + back_row[i + 1];
            v[0][i] = 0;
        }
    }

    print("backrow");
    linebreak1;
    trav(back_row) print(x);
    linebreak1;
    for (int i = n - 2; i >= 0; i--)
    {
        vi curr_row(n, -1);
        // vi curr_col(n);
        for (int j = n - 1; j >= 0; j--)
        {
            if (v[i][j] != -1)

                if (j + 1 < n)
                {
                    int max1 = INT_MIN;
                    if (back_row[j] != -1)
                        max1 = back_row[j];
                    int max2 = INT_MIN;
                    if (curr_row[j + 1] != -1)
                        max2 = curr_row[j + 1];

                    if (i == 0 and j == 0)
                    {
                        deb2(max1, max2);
                    }

                    int maxi = max(max1, max2);
                    if (maxi == max1 and max1 != INT_MIN)
                    {
                        curr_row[j] = maxi + v[i][j];
                        v[i + 1][j] = 0;
                        // v[i][j + 1] = curr_row[j + 1];
                        v[i][j + 1] = v2[i][j + 1];

                        // curr_col[j] = maxi;
                    }
                    else if (max2 != INT_MIN)
                    {
                        curr_row[j] = maxi + v[i][j];
                        v[i][j + 1] = 0;
                        // v[i + 1][j] = back_row[j];
                        v[i + 1][j] = v2[i + 1][j];
                        // curr_col[j] = maxi;
                    }
                }
                else
                {
                    if (v[i][n - 1] != -1 and back_row[j] != -1)
                    {
                        curr_row[n - 1] = v[i][n - 1] + back_row[n - 1];
                        v[i + 1][n - 1] = 0;
                    }
                }
        }
        // print(smile2);
        print("🥊");
        trav(curr_row) print(x);
        linebreak1;
        back_row = curr_row;
        // back_col = curr_col;
    }
    debline(back_row[0]);

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
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
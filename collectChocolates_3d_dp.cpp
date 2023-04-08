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
    int n, m;
    cin >> n >> m;
    vvi v(n, vi(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> v[i][j];
    }
    linebreak1;
    trav(v)
    {
        trav2(x) print(y);
        nline;
    }
    vvi back(m, vi(m, -1e8)); // back is backdp
    vvi curr(m, vi(m));       // curr is currdp

    // now simply we have possible m*m cases for robot1 and robot2's positions at a time:-
    back[0][m - 1] = v[0][0] + v[0][m - 1];
    // back[0][0] = v[0][0];
    // back[m - 1][m - 1] = v[0][m - 1];
    // for (int j1 = 0; j1 < m - 1; j1++)
    // {
    //     back[0][j1] = v[0][0];
    // }
    // for (int j2 = 1; j2 < m; j2++)
    // {
    //     back[j2][m - 1] = v[0][m - 1];
    // }

    linebreak1;
    trav(back)
    {
        trav2(x) print(y);
    }
    linebreak1;
    int maxii = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                // now see possible 9 directions from where we can consider our answer:-
                //
                int maxi = -1e8;
                for (int d1 = -1; d1 <= 1; d1++)
                {
                    for (int d2 = -1; d2 <= 1; d2++)
                    {
                        int x1 = j1 + d1;
                        int x2 = j2 + d2;
                        int value = 0;
                        if (j1 == j2)
                            value += v[i][j1];
                        else
                        {
                            value += (v[i][j1] + v[i][j2]);
                        }

                        if (x1 >= 0 and x1 < m and x2 >= 0 and x2 < m)
                        {
                            // value += max(value, back[x1][x2]);
                            value += back[x1][x2];
                        }
                        else
                        {
                            value = -1e8;
                        }

                        /*   if (j1 == j2)
                              value += v[i][j1];
                          else
                          {
                              value += (v[i][j1] + v[i][j2]);
                          } */
                        maxi = max(maxi, value);
                        maxii = max(maxi, maxii);
                    }
                }
                curr[j1][j2] = maxi;
            }
        }

        nline;
        print("🥊");
        linebreak1;
        trav(curr)
        {
            trav2(x) print(y);
        }
        linebreak1;

        back = curr;
    }

    debline(maxii);

    linebreak1;
    trav(back)
    {
        trav2(x) print(y);
    }
    linebreak1;
    trav(curr)
    {
        trav2(x) print(y);
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
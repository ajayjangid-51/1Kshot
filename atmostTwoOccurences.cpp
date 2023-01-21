#include <bits/stdc++.h>
using namespace std;

#define lb lower_bound
#define ub upper_bound
#define sz(x) x.size()

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
#define deb(x) cout << #x << " = " << x << endl
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
void solve()
{
    // vi A = {1, 2, 3, 1, 3, 2, 3, 1, 2, 3};
    // vi A = {1, 1, 1, 2, 2, 2};
    // vi A = {1, 1, 2, 2};
    vi A = {58,
            38, 60, 24,
            42, 30, 79, 17, 36, 91, 43, 89, 7, 41, 43, 65, 49, 47, 6, 91 /*19*/, 30, 71, 51, 7, 2, 94, 49, 30, 24, 85, 55, 57, 41, 67, 77, 32, 9, 45, 40, 27, 24, 38, 39, 19, 83, 30 /*45*/, 42, 34, 16, 40, 59, 5, 31, 78, 7, 74, 87, 22, 46, 25, 73, 71, 30, 78, 74, 98, 13, 87, 91, 62, 37, 56};
    // sort(A.begin(), A.end());
    deb(A.size());
    int i = 0, j = A.size() - 1;
    int i1 = -1, j1 = -1;
    map<int, int> m;
    while (i < j)
    {
        if (i1 > 0 and j1 > 0)
            break;
        deb(A[i]);
        if (m[A[i]] < 2)
        {
            m[A[i++]]++;
            deb(m[A[i - 1]]);
        }
        else
        {
            i1 = i;
            deb(m[A[i]]);
        }
        deb(A[j]);

        if (m[A[j]] < 2)
        {
            m[A[j--]]++;
            deb(m[A[j + 1]]);
        }
        else
        {
            j1 = j;
            deb(m[A[j]]);
        }
        linebreak1;
    }
    deb(i1);
    deb(j1);
    linebreak1;
    trav(m) print(x.first), print("-"), print(x.second), nline;
    int ans = j1 - i1 + 1;
    debline(ans);

    int i2 = -1;
    map<int, int> m2;
    int i3 = 0;
    while (m2[A[i3]] < 2 and i3 < A.size())
    {
        m2[A[i3++]]++;
    }
    debline(i3);
    deb(A.size() - i3);

    map<int, int> m3;
    int j2 = -1;
    int j3 = A.size() - 1;
    while (m3[A[j3]] < 2 and j3 >= 0)
    {
        m3[A[j3--]]++;
    }
    debline(j3);
    // deb()
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
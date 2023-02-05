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
#define vvc vector<vector<char>>
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
    vector<vs> A = {{"5", "3", ".", ".", "7", ".", ".", ".", "."},
                    {"6", ".", ".", "1", "9", "5", ".", ".", "."},
                    {".", "9", "8", ".", ".", ".", ".", "6", "."},
                    {"8", ".", ".", ".", "6", ".", ".", ".", "3"},
                    {"4", ".", ".", "8", ".", "3", ".", ".", "1"},
                    {"7", ".", ".", ".", "2", ".", ".", ".", "6"},
                    {".", "6", ".", ".", ".", ".", "2", "8", "."},
                    {".", ".", ".", "4", "1", "9", ".", ".", "5"},
                    {".", ".", ".", ".", "8", ".", ".", "7", "9"}};
    unordered_map<string, bool> m;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[0].size(); j++)
        {
            if (A[i][j] != ".")
            {
                string r("(" + A[i][j] + ")" + to_string(i));
                string c(to_string(j) + "(" + A[i][j] + ")");
                string box(to_string(i / 3) + "(" + A[i][j] + ")" + to_string(j / 3));
                if (m.count(r) > 0 or m.count(c) > 0 or m.count(box) > 0)
                {
                    debline("false");
                    return;
                }
                m[r] = 1;
                m[c] = 1;
                m[box] = 1;
            }
        }
    }
    debline("true");
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
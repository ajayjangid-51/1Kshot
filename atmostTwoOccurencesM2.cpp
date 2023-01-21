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
    vi A = {58,
            38, 60, 24,
            42, 30, 79, 17, 36, 91, 43, 89, 7, 41, 43, 65, 49, 47, 6, 91 /*19*/, 30, 71, 51, 7, 2, 94, 49, 30 /*27 */, 24, 85, 55, 57, 41, 67, 77, 32, 9, 45, 40, 27, 24, 38, 39, 19, 83, 30 /*45*/, 42, 34, 16, 40, 59, 5, 31, 78, 7, 74, 87, 22, 46, 25, 73, 71, 30, 78, 74, 98, 13, 87, 91, 62, 37, 56};

    vi B = {58, 38, 60, 24, 42, 30, 79, 17, 36, 91, 43, 89, 7, 41, 43, 65, 49, 47, 6, 91, 30, 71, 51, 7, 2, 94, 49, 30};

    int occ = 0;
    int n = A.size();
    vector<int> v;
    map<int, int> countOcc;
    for (int i : A)
    {
        countOcc[i]++;
        if (countOcc[i] == 3)
        {
            v.push_back(i);
            occ++;
        }
    }
    if (occ == 0)
    {
        debline("000");
        return;
    }
    debline(occ); // "occ" represents no. of elements with frequency greater than 2.
    linebreak1;
    trav(v) print(x);
    linebreak1;
    int r = -1, ans = n;
    for (int i = 0; i < n; i++)
    {
        while (r + 1 < n and occ)
        {
            r++;
            countOcc[A[r]]--;
            if (countOcc[A[r]] == 2)
                occ--;
        }
        debline(occ);
        if (occ == 0)
        {

            ans = min(ans, r - i + 1);
            print(r);
            print(i);
            linebreak1;
        }
        countOcc[A[i]]++;
        if (countOcc[A[i]] == 3)
            occ++;
    }
    debline(ans);
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
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
    vi A = {1, 4, 5, 8, 10};
    vi B = {6, 9, 15};
    vi C = {2, 3, 6, 6};
    int minidiff, currmindiff;
    minidiff = abs(max(*A.rbegin(), max(*B.rbegin(), *C.rbegin())) - min(*A.rbegin(), min(*B.rbegin(), *C.rbegin())));
    debline(minidiff);
    int i = A.size() - 1, j = B.size() - 1, k = C.size() - 1;

    while (i >= 0 and j >= 0 and k >= 0)
    {

        int currMax = max(A[i], max(B[j], C[k]));

        // currmindiff = abs(max(A[i], max(B[j], C[k])) - min(A[i], min(B[j], C[k])));
        currmindiff = abs(currMax - min(A[i], min(B[j], C[k])));
        debline(currmindiff);
        if (minidiff > currmindiff)
            minidiff = currmindiff;
        debline(minidiff);
        if (currMax == A[i])
        {
            i--;
        }
        else if (currMax == B[j])
            j--;
        else
            k--;
    }
    debline(minidiff);
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
#include <bits/stdc++.h>
using namespace std;

#define lb lower_bound
#define ub upper_bound
#define size(x) x.size()

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
int quicksortpartition(vi &v, int l, int r)
{

    int pivot = l;
    int i = l;
    int j = r;
    while (1)
    {

        while (v[++i] < v[pivot])
            ;
        while (v[--j] > v[l])
            ;
        if (i >= j)
            break;
        swap(v[i], v[j]);
    }
    swap(v[j], v[pivot]);
    return j;
}
void solve()
{
    // vi v = {3, 2, 1, 5, 6, 4};
    vi v = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    // int k = 2;
    int k = 4;
    v.push_back(INT_MAX);
    int n = size(v);
    k = n - k - 1;
    int p = 0, l = 0, r = n - 1;
    while (1)
    {
        int j = quicksortpartition(v, l, r);
        if (j < k)
        {
            l = j + 1;
        }
        else if (j > k)
        {
            v[j] = INT_MAX;
            r = j;
        }
        else
            break;
    }
    debline(v[k]);
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
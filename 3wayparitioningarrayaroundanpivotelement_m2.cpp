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

void solve()
{
    vi v = {1, 3, 2, 2, 3, 1};
    int n = size(v);
    // first do the 3waypartitioning aroud the median as a pivot.
    // first get the median;
    auto midindex = v.begin() + (n / 2);
    nth_element(v.begin(), midindex, v.end());
    int mid = *midindex;

    // 3wayparitioning:-
    int i = 0, j = 0, e = n - 1;
    // here we will keep 0 to i-1 bigger elements
    // and i to j-1 equal elements
    // and j to e smaller elements

    while (j <= e)
    {
        if (v[j] > mid) // means the unkonws elements seems to greater than median so, put it in 0 to i-1 area. so for that we have bring this current element to 0 to i-1 area so to do that we first increase the (0 to i-1) window by increasing i++ and swaping that the current element that position with our current position and now at our current position will contain equal element bcoz we know ki previously i to j-1 range is containing equal elements as we have mentioned above in line 67to71.
        {
            swap(v[i], v[j]);
            i++;
            j++;
        }
        else if (v[j] < mid)
        {
            swap(v[j], v[e]);
            e--;
        }
        else
            j++;
    }
    trav(v) print(x);
    nline;
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
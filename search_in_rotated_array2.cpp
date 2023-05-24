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
#define onered cout << "🔴"
#define twoblue cout << "🔵"
#define threeyellow cout << "🟡"
#define fourpurple cout << "🟣"
#define fivebrown cout << "🟤"
#define sixgreen cout << "🟢"
#define sevenwhite cout << "⚪"
#define eightwheel cout << "🛞"
#define ninering cout << "⭕"
#define tenpoint cout << "👉"
#define elevenhand cout << "🤚🏻"
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
    int n, k;
    cin >> n >> k;
    vi v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    linebreak1;
    trav(v) print(x);
    linebreak1;

    int s = 0, e = n - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        deb3(mid, v[mid], v[s]);
        if (v[mid] == k or v[s] == k)
        {
            debline("true");
            return;
        }
        if (v[s] == v[mid])
        {
            onered;
            s++;
            continue;
        }
        // if v[mid]>v[start] then mtlb from start_to_mid the array is sorted.
        if (k > v[s] and v[mid] > v[s])
        { // if both are in first-array
            if (k > v[mid])
            {
                s = mid + 1;
            }
            else
            {

                e = mid - 1;
            }
        }
        else if (k < v[s] and v[mid] < v[s])
        { // if both are in second-array.
            if (k < v[mid])
            {
                e = mid - 1;
            }
            else
            {

                s = mid + 1;
            }
        }
        else if (k > v[s] and v[mid] < v[s])
        { // if key is in first and v[mid] is in second
            e = mid - 1;
        }
        // else if(k<=v[s] and v[mid]>v[s])
        else
        { // if key is in second and v[mid] in first.
            s = mid + 1;
        }
    }
    debline("false");
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
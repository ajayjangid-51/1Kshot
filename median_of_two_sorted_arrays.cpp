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
#define printn(x) cout << x << "\n"
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
int kthElement(vi v1, vi v2, int n, int m, int k)
{
    // if (k == 1)
    // {
    //     if (n > 0)
    //         return v1[0];
    //     return v2[0];
    // }
    onered;
    printn(k);
    v1.push_back(INT_MAX);
    v2.push_back(INT_MAX);
    // v1[n] = INT_MAX;
    // v2[m] = INT_MAX;

    long long s = k - m, e = min(n, k);
    if (s <= 0)
        s = 0;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        twoblue;
        deb(mid);
        int i1 = mid - 1, i2 = k - mid - 1;
        // deb(mid);
        deb2(i1, i2);
        // if (i1 < 0)
        // {
        //     return v2[i2];
        // }
        // if (i2 < 0)
        //     return v1[i1];

        if (i1 > -1 and v1[i1] > v2[i2 + 1])
        {
            e = mid - 1;
        }
        else if (i2 > -1 and v2[i2] > v1[i1 + 1])
        {
            s = mid + 1;
        }
        else
        {
            if (i1 > -1 and i2 > -1)
                return (max(v1[i1], v2[i2]));
            if (i1 > -1)
                return v1[i1];
            return v2[i2];

            // if(t == v1[i1]) return i1;
            // return i2;
            // return t;
        }
    }
    return 0;
}
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size(), m = nums2.size();
    vi v1 = nums1;
    int d = 1e6 + 10;
    v1.push_back(d);
    vi v2 = nums2;
    v2.push_back(d);

    double a = kthElement(v1, v2, n, m, ((n + m) / 2) + 1);
    deb(a);
    if ((n + m) % 2)
    {
        return a;
    }
    int mid = (n + m) / 2;
    deb(mid);
    linebreak1;
    double b = kthElement(v1, v2, n, m, mid);
    deb(b);
    // double b = 0;
    // cout << b<< ".";
    return (a + b) / 2;

    // return
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vi v1(n), v2(m);
    for (int i = 0; i < n; i++)
        cin >> v1[i];
    for (int i = 0; i < m; i++)
        cin >> v2[i];
    linebreak1;
    double ans = findMedianSortedArrays(v1, v2);

    debline(ans);
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
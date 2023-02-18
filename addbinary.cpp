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
// #define size(x) x.size()
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
    // string a("1010"), b("111011");
    string a("1111"), b("1111");
    // string a("100"), b("110110");
    // string a("110010"), b("10111");
    int n1 = a.size(), n2 = b.size();
    deb2(n1, n2);
    int m = min(n1, n2);
    string ms;
    ms = (max(n1, n2) == n1) ? a : b;
    deb(ms);
    int i = n1 - 1, j = n2 - 1;
    int c = 0;
    // for(int )
    string ans(max(n1, n2) + 1, '0');
    int l = ans.size() - 1;
    int k = 0;
    debline(l);
    for (; k < m; k++)
    {
        if (a[i] == '1' and b[j] == '1')
        {
            if (c)
            {
                ans[l--] = '1';
                // c = 0;
            }
            else
            {

                ans[l--] = '0';
                c = 1;
            }
        }
        else if (a[i] == '0' and b[j] == '0')
        {
            if (c)
            {
                c = 0;
                ans[l--] = '1';
            }
            else
                ans[l--] = '0';
        }
        else
        {
            if (c)
            {
                // c = 0;
                ans[l--] = '0';
            }
            else
            {
                ans[l--] = '1';
            }
        }
        i--;
        j--;
    }
    debline(ans);
    debline(l);
    for (; k < max(n1, n2); k++)
    {
        if (c)
        {
            c = 0;
            if (ms[l - 1] == '1')
            {
                ans[l--] = '0';
                c = 1;
            }
            else
            {
                ans[l--] = '1';
            }
        }
        else
        {
            ans[l] = ms[l - 1];

            // debline(ans);
            // deb4(ans, k, l, ms[l]);
            deb(ms[l]);
            deb3(ans, k, l);
            linebreak1;
            l--;
        }
    }
    debline(ans);
    if (c)
        ans[l] = '1';
    // else return ans.substr(1);
    else
        ans = ans.substr(1);
    debline(ans);
    // return ans;
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
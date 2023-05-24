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
    string s;
    int k;
    cin >> s >> k;
    deb2(s, k);

    int mplast[26] = {0};
    int siz1 = 0;
    int mpcurr[26] = {0};
    int siz2 = 0;
    int n = s.size();
    int j = 0;
    int ans = 0;
    // for (int i = 0; i < n;)
    int i = 0;
    int f = 0;
    while (j < n)
    {
        while (i < n and siz2 <= k)
        {
            int t = s[i] - 'a';
            if (mpcurr[t] == 0)
                siz2++;
            mpcurr[t]++;
            i++;
        }
        if (siz2 > k)
        {
            i--;
            int t = s[i] - 'a';
            mpcurr[t]--;
            siz2--;
        }
        while (j < n and siz1 <= k - 1)
        {
            int t = s[j] - 'a';
            if (mplast[t] == 0)
                siz1++;
            mplast[t]++;
            j++;
        }
        if (siz1 > k - 1)
        {
            j--;
            int t = s[j] - 'a';
            mplast[t]--;
            siz1--;
        }
        deb2(i, j);
        ans += (i - j);
        int t = s[f] - 'a';
        mplast[t]--;
        if (mplast[t] == 0)
            siz1--;
        mpcurr[t]--;
        if (mpcurr[t] == 0)
            siz2--;
        deb2(siz1, siz2);
        f++;
    }
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
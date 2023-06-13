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
    string s1, s2;
    cin >> s1 >> s2;

    int start = 0;     // start is "start of our answer required substring"
    int len = INT_MAX; // len is "required substring length"
    int j = 0;
    // for (int i = 0; i < s1.size(); i++)
    int i = 0;
    while (i < s1.size())
    {
        if (j < s2.size() and s1[i] == s2[j])
        {

            j++;
            i++;
        }
        else
            i++;
        if (j == s2.size()) // mtlb we have found some substring which can be s2'ssubsequence.
        {
            int l1 = i - 1, l2 = j - 1;
            while (l2 >= 0)
            {
                if (s1[l1] == s2[l2])
                {
                    l1--;
                    l2--;
                }
                else
                    l1--;
            }
            // int t = i - (l1 + 1);
            // deb(t);
            if (len > (i - (l1 + 1)))
            {
                // print(onered);
                // onered;
                start = l1 + 1;
                len = i - (l1 + 1);
            }
        }
    }

    if (len == INT_MAX)
    {
        debline("no");
    }
    else
    {
        debline(s1.substr(start, len));
    }
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
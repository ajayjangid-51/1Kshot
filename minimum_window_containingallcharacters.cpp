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
    string s("timetopractice"), p("toc");
    cin >> s >> p;
    vector<int> m1(26, 0);
    vector<int> m2(26, 0);
    for (auto x : p)
    {
        int ind = x - 'a';
        // deb(ind);
        m2[ind]++;
    }
    trav(m2) print(x);
    nline;
    string ans(s);

    int i = 0, j = 0; // applying slidingwindow startergy which is mtlb acquire-release statergy.
    int counter = 0;  // this counter is flag for acquiring-or-releasing.
    // if(counter == p.size()) the start relasing or if(counter<p.size()) keep acquiring
    // for (; i < s.size();)
    for (; j < s.size(); j++)
    // while (i < s.size())
    {
        int ind = s[j] - 'a';
        if (m1[ind] < m2[ind])
        {
            counter++;
            m1[ind]++;
        }
        else
        {
            m1[ind]++;
        }

        // if (counter == p.size())
        // {
        //     int len = (j - i) + 1;
        //     // debline(len);
        //     // deb(len);
        //     debline(s.substr(i, len));
        //     if (len < ans.size())
        //     {
        //         ans = s.substr(i, len);
        //         deb(ans);
        //     }
        // }

        while (counter == p.size() and i < j) // mtlb acquire.
        {
            int ind = s[i] - 'a';
            int len = (j - i) + 1;
            // debline(len);
            // deb(len);
            debline(s.substr(i, len));
            if (len < ans.size())
            {
                ans = s.substr(i, len);
                deb(ans);
            }
            if (m1[ind] == m2[ind])
            {
                counter--;
                m1[ind]--;
                // break;
            }
            else
            {
                m1[ind]--;
            }
            i++;
        }
        // i--;
        // deb(counter);
        // deb(i);
        // debline(s.substr(i));

        // while (counter == p.size() and i < s.size())
        // {
        //     int ind = s[i] - 'a';
        //     if (m2[ind] == m1[ind])
        //     {
        //         counter--;
        //         m2[ind]--;
        //         break;
        //     }
        //     else
        //     {
        //         m2[ind]--;
        //     }
        //     i++;
        // }
    }
    // int len  = (j-i)+1;
    deb2(i, j);

    debline(ans);
}
// sliding window meh acquiring forloop se krni hai and releasing whileloop se krni hai. and whileloop meh hi answer ko update krna hai.

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
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
// stack<int> s({2, 3, 1});
// stack<int> s({5, -2, 9, -7, 3});
stack<int> s({3, -7, 9, -2, 5});
bool f = 0;
void fn(int t)
{
    s.pop();

    if (!s.empty())
        fn(s.top());

    if (s.empty())
    {
        // if (f)
        // {
        //     return;
        // }
        // else
        // {

        s.push(t);
        // }
    }
    else
    {
        // if(s.top())
        if (s.top() <= t)
        {
            s.push(t);
        }
        else
        {
            stack<int> s2;
            while (!s.empty() and s.top() > t)
            {

                s2.push(s.top());
                s.pop();
            }
            s.push(t);
            while (!s2.empty())
            {
                s.push(s2.top());
                s2.pop();
            }
            // f = 0;
        }
    }
}

void solve()
{
    // stack<int> s({2, 3, 1});
    // s = {2, 3, 1};
    debline(size(s));
    fn(s.top());
    debline(size(s));
    while (!s.empty())
    {
        print(s.top());
        s.pop();
    }
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
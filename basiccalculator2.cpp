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
void solve()
{
    string s("3+2*2");
    stack<int> S;
    int prev = 0;
    int i = 0;
    while (i < size(s))
    {
        if (s[i] == '-')
        {
            // S.push(-stoi(s[++i]));
            S.push(-1 * stoi(to_string(s[++i])));
            i++;
        }
        else if (s[i] == '*' or s[i] == '/')
        {
            int t = S.top();
            S.pop();
            t *= stoi(to_string(s[++i]));
            S.push(t);
            i++;
        }
        else
        {
            if (s[i] != '+')
            {
                // debline(s[i]);
                // debline(to_string(s[i++]));
                debline(s[i]);
                debline(to_string(s[i]));

                S.push(stoi(to_string(s[i++])));
                // debline(S.top());
            }
            else
                i++;
        }
    }
    // deb(S.size());
    // print(S.size());
    // cout << S.size();
    deb(size(S));
    while (!S.empty())
        print(S.top()), S.pop();
    // print("Hi");
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
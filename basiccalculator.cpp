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
    // string s("3-256*27");
    string s("3+2*2");
    string signs;
    vi nums;
    string tmp;
    for (int i = 0; i < size(s); i++)
    {
        if (s[i] >= '0' and s[i] <= '9')
        {
            tmp.push_back(s[i]);
        }
        else
        {
            nums.push_back(stoi(tmp));
            tmp.clear();
            signs.push_back(s[i]);
        }
    }
    nums.push_back(stoi(tmp));
    print(signs);
    nline;
    trav(nums) print(x);
    linebreak1;

    stack<int> stk;
    stk.push(nums[0]);
    int i = 1;
    int j = 0;
    // while(!stk.empty()){
    while (i < size(nums))
    {
        if (signs[j] == '*' or signs[j] == '/')
        {
            int tp = stk.top();
            stk.pop();
            int sum = tp;
            if (signs[j] == '*')
            {
                sum *= nums[i++];
            }
            else
            {
                sum /= nums[i++];
            }
            stk.push(sum);
            j++;
        }
        else
        {
            if (signs[j] == '-')
            {
                stk.push(-nums[i++]);
            }
            else
            {
                stk.push(nums[i++]);
            }
            j++;
        }
    }
    int ans = 0;
    while (!stk.empty())
    {
        ans += stk.top();
        stk.pop();
    }
    debline(ans);
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
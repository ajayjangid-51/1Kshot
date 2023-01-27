#include <bits/stdc++.h>
using namespace std;

#define lb lower_bound
#define ub upper_bound
#define sz(x) x.size()

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
int x[4] = {0, 0, -1, +1};
int y[4] = {-1, +1, 0, 0};
void dfs(int i, int j, vector<vector<char>> &A, vector<vector<bool>> &visited)
{
    // print('I');
    deb(i);
    deb(j);
    A[i][j] = '1';
    for (int k = 0; k < 4; k++)
    {
        int i1 = i + x[k];
        int j1 = j + y[k];
        if (i1 >= 0 and i1 < A.size() and j1 >= 0 and j1 < A[0].size() and A[i1][j1] == 'O')
        {
            print(smile2);
            A[i1][j1] = '1';
            // visited[i1][j1] = 1;
            dfs(i1, j1, A, visited);
        }
    }
}
void solve()
{
    vector<vector<char>> A = {{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};

    // trav boundary..
    int n = A.size(), m = A[0].size();
    vector<vb> visited(n, vb(m, 0));
    for (int i = 0; i < n; i++)
    {
        if (A[i][0] == 'O')
        {
            // if (!visited[i][0])
            dfs(i, 0, A, visited);
        }
        if (A[i][m - 1] == 'O')
        {
            // if (!visited[i][m - 1])
            dfs(i, m - 1, A, visited);
        }
    }
    for (int i = 1; i < m - 1; i++)
    {
        if (A[0][i] == 'O')
        {
            if (!visited[0][i])
            {
                dfs(0, i, A, visited);
            }
        }
        if (A[n - 1][i] == 'O')
        {
            if (!visited[n - 1][i])
            {
                dfs(n - 1, i, A, visited);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (A[i][j] == '1')
                A[i][j] = 'O';
            else
                A[i][j] = 'X';
        }
    }
    trav(A)
    {
        trav2(x) print(y);
        nline;
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
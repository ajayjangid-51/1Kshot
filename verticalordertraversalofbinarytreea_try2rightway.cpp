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
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void solve()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    // root->left->right->left = new Node(10);
    // root->left->right->right = new Node(14);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    map<int, map<int, multiset<int>>> m;
    queue<pair<Node *, pair<int, int>>> q;
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        pair<Node *, pair<int, int>> f = q.front();
        q.pop();
        m[f.second.first][f.second.second].insert(f.first->data);
        if (f.first->left)
            q.push({f.first->left, {f.second.first - 1, f.second.second + 1}});
        if (f.first->right)
            q.push({f.first->right, {f.second.first + 1, f.second.second + 1}});
    }
    vector<vector<int>> ans;
    linebreak1;

    trav(m)
    {
        print(x.first);
        print("---");
        trav2(x.second)
        {
            print(y.first);
            print("-");
            for (auto z : y.second)
                print(z);
            nline;
        }
        nline;
        nline;
    }

    linebreak1;
    for (auto x : m)
    {
        vector<int> v;
        for (auto y : x.second)
        {
            // v.push_back(vector<int>(y.second.begin(), y.second.end()));
            for (auto z : y.second)
            {
                v.push_back(z);
            }
        }
        ans.push_back(v);
    }
    linebreak1;
    trav(ans)
    {
        trav2(x) print(y);
        nline;
    }
    linebreak1;
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
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
    root->left = new Node(3);
    root->left->left = new Node(5);
    root->left->left->left = new Node(6);
    root->right = new Node(2);
    root->right->right = new Node(9);
    root->right->right->left = new Node(7);

    map<Node *, int> m;
    queue<Node *> q;
    q.push(root);
    m[root] = 1;
    int maxi = 0;
    while (!q.empty())
    {
        int s = 0, e = 0;
        int n = size(q);
        for (int i = 0; i < n; i++)
        {
            Node *f = q.front();
            q.pop();
            if (i == 0)
            {
                s = m[f];
            }
            if (i == n - 1)
            {
                e = m[f];
            }
            if (f->left)
            {

                q.push(f->left);
                m[f->left] = 2 * m[f];
            }
            if (f->right)
            {

                q.push(f->right);
                m[f->right] = (2 * m[f]) + 1;
            }
        }
        maxi = max(maxi, (e - s) + 1);
    }
    debline(maxi);
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
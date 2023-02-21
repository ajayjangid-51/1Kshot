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
    root->left->right = new Node(2);
    // root->left->right->left = new Node(10);
    // root->left->right->right = new Node(14);
    root->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(6);

    if (!root)
        return;
    vi pre, in, post;

    stack<pair<Node *, int>> s;
    s.push({root, 1});
    while (!s.empty())
    {
        if (s.top().second == 3)
        {
            post.push_back(s.top().first->data);
            s.pop();
        }
        else if (s.top().second == 1) // 1 denotes that for firstly it will be element of pre.
        {
            pre.push_back(s.top().first->data);
            s.top().second = 2;
            if (s.top().first->left)
            {
                s.push({s.top().first->left, 1});
            }
            // s.push({})
        }
        else
        {
            in.push_back(s.top().first->data);
            s.top().second = 3;
            if (s.top().first->right) // we are on the mid-node means left is alreay traversed to now push the right one.
            {
                s.push({s.top().first->right, 1});
            }
        }
    }
    trav(pre) print(x);
    nline;
    trav(in) print(x);
    nline;
    trav(post) print(x);
    nline;
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
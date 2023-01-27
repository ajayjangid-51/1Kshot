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
struct ListNode
{
    int key;
    int val;
    ListNode *prev;
    ListNode *next;
    ListNode(int k, int x) : key(k), val(x), prev(NULL), next(NULL) {}
};
class LRUCache
{
public:
    int c;
    map<int, ListNode *> m;
    ListNode *head = NULL;
    ListNode *tail = head;
    LRUCache(int capacity)
    {
        c = capacity;
        head = NULL;
    }

    int get(int key)
    {
        if (m.find(key) != m.end())
        {
            m[key]->prev->next = m[key]->next;
            m[key]->next->prev = m[key]->prev;
            m[key]->next = head;
            m[key]->prev = tail;
            return m[key]->val;
        }
        else
            return -1;
    }

    void put(int key, int value)
    {
        if (m.find(key) != m.end())
        {
        }
        else
        {
            if (m.size() == c)
            {
                m.erase(tail->key);
                head->prev = tail->prev;
                tail->prev->next = head;
            }
            ListNode *node = new ListNode(key, value);
            m[key] = node;
            node->next = head;
            node->prev = tail;
            if (head)
                head->prev = node;
            head = node;
            if (!head->next and !head->prev)
            {
                tail = head;
            }
            else
                tail = head->prev;
            tail->next = head;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main()
{
    io_faster
    file();
    int t = 1;
    //	cin >> t;
    while (t--)
    {
        // solve();
    }
    return 0;
}
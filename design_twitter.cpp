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

class Twitter
{
    map<int, set<int>> fmp;
    map<int, vector<pair<int, int>>> tmp;
    int time = 0;

public:
    Twitter() {}
    void postTweet(int userId, int tweetId)
    {
        tmp[userId].push_back({time++, tweetId});
    }
    vector<int> getNewsFeed(int userId)
    {
        // print("hi");
        // priority_queue<pii, vector<pii>, greater<pii>> pq;
        priority_queue<pii> pq;
        for (auto x : fmp[userId])
        {
            // print(x);
            for (auto y : tmp[x])
            {
                pq.push({y.first, y.second});
                if (pq.size() > 10)
                    break;
            }
        }
        for (auto y : tmp[userId])
        {
            pq.push({y.first, y.second});
            if (pq.size() > 10)
                break;
        }
        vi ans;
        for (int i = 0; i < 10 and !pq.empty(); i++)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        linebreak1;
        trav(ans) print(x);
        linebreak1;
        return ans;
    }
    void Follow(int followerId, int followeeId)
    {
        fmp[followerId].insert(followeeId);
    }
    void unFollow(int followerId, int followeeId)
    {
        fmp[followerId].erase(followeeId);
    }
};
void solve()
{
    Twitter t1;
    t1.postTweet(1, 5);
    t1.getNewsFeed(1);
    t1.Follow(1, 2);
    t1.postTweet(2, 6);
    t1.getNewsFeed(1);
    t1.unFollow(1, 2);
    t1.getNewsFeed(1);
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
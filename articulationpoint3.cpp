#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define siz(v) v.size()
#define trav(v) for (auto x : v)
#define range(v) v.begin(), v.end()
class Solution
{
public:
    void fn(int i, int p, vector<int> adj[], vi &toa, vi &low, vb &visited, int &at, vi &ans)
    {
        toa[i] = at;
        low[i] = at;
        visited[i] = 1;
        int child = 0;
        for (auto x : adj[i])
        {
            if (x == p)
                continue;
            if (!visited[x])
            {
                fn(x, i, adj, toa, low, visited, ++at, ans);

                low[i] = min(low[i], low[x]);
                if (low[x] >= toa[i] and p != -1)
                {
                    ans.push_back(i);
                }
                child++;
            }
            else
            {
                low[i] = min(low[i], toa[x]);
            }
        }
        if (p == -1 and child > 1)
        {
            ans.push_back(i);
        }
    }
    vector<int> articulationPoints(int n, vector<int> adj[])
    {
        // Code here
        vi toa(n);
        vi low(n);
        vb visited(n, 0);
        int at = 0;
        vi ans;
        fn(0, -1, adj, toa, low, visited, at, ans);
        set<int> s;
        for (auto x : ans)
            s.insert(x);
        // sort(ans.begin(), ans.end());
        ans.clear();
        for (auto x : s)
            ans.push_back(x);
        if (ans.size() == 0)
            return {-1};
        return ans;
    }
};
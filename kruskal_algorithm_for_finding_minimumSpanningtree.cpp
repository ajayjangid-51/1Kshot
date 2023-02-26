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

class disjointSetORUnionfindStructure
{
    // private:
public:
    vi parent;
    vi size;

    disjointSetORUnionfindStructure(int n) // 0 based indexing is considered.
    {
        parent.assign(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }

        size.assign(n, 1);
    }

    int find(int x) // x stands for any element of set.
    {
        while (parent[x] != x)
            x = parent[x];
        return x;
    }
    void uninte(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a != b)
        {
            if (size[a] < size[b])
            {
                swap(a, b); // means we are always considering set "a" as bigger one.
            }
            size[a] += size[b];
            parent[b] = a;
        }
    }
};
void solve()
{
    disjointSetORUnionfindStructure obj1(8);
    // trav(obj1.parent) print(x);
    // nline;
    // trav(obj1.size) print(x);
    // nline;

    // now kruskals algorithm for finding MST(minimum spanning tree):-
    // so graph is given as a edgelist representation:-
    vvi edgelist = {
        {1, 2, 3},
        {1, 5, 5},
        {2, 5, 6},
        {2, 3, 5},
        {5, 6, 2},
        {3, 6, 3},
        {3, 4, 9},
        {6, 4, 7}};
    // sort edgelist:- (we will sort vis using lambdafunction:-)
    sort(edgelist.begin(), edgelist.end(), [](vector<int> a, vector<int> b)
         {
             // bydefault it is a<b considered so:-
             if (a[2] < b[2])
                 return 1;
             return 0; });
    linebreak1;
    trav(edgelist) print(x[0]), print(x[1]), print(x[2]), nline;

    int sum = 0; // this will be weight of MST.
    trav(edgelist)
    {
        int a = x[0], b = x[1], w = x[2];
        if (obj1.find(a) != obj1.find(b))
        {
            sum += w;
            obj1.uninte(a, b);
        }
    }
    debline(sum);
    // now we will print the MST:-
    trav(obj1.parent) print(x);
    nline;
    trav(obj1.size) print(x);
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

/*  vvi edgelist;
            for(int i= 0;i<V;i++){
                for(int j = 0;j<adj[i].size();j++){
                    edgelist.push_back({i,adj[i][j][0] , adj[i][j][1]});
                }
            } */

/*
accepted-code just minor change in edgelist datastructure that use vector<pair<int,pair> instead of using 2dvector. it will give timelimit. */
/*    int spanningTree(int V, vector<vector<int>> adj[])
    {
            // disjointSetORUnionfindStructure obj1(V); // if 0 based indexing is used then "V" or else "V+1".
            for(int i= 0;i<V;i++) {parent.push_back(i); size.push_back(1);}
            vector<pair<int, pair<int, int>>> edgelist;
            for(int i= 0;i<V;i++){
                for(int j = 0;j<adj[i].size();j++){
                    // edgelist.push_back({i,adj[i][j][0] , adj[i][j][1]});
                    // edgelist[{i, adj[i][j][0]}] = adj[i][j][1];
                    // edgelist[adj[i][j][1]] = {i , adj[i][j][0]};
                    edgelist.push_back({adj[i][j][1] , {i,adj[i][j][0]}});
                }
            }

            sort(edgelist.begin() , edgelist.end());

        // sort(edgelist.begin(), edgelist.end(), [](vector<int> a, vector<int> b)
        //  {
        //      // bydefault it is a<b considered so:-
        //      if (a[2] < b[2])
        //          return 1;
        //      return 0; });
    // linebreak1;
    // trav(edgelist) print(x[0]), print(x[1]), print(x[2]), nline;

    int sum = 0; // this will be weight of MST.
    for(auto x:edgelist)
    {
        // int a = x[0], b = x[1], w = x[2];
        // int a = x.first.first , b = x.first.second , w = x.second;
        int w = x.first , a = x.second.first , b = x.second.second;
        if (find(a) != find(b))
        {
            sum += w;
            uninte(a, b);
        }
    }
    // debline(sum);
    return sum;
    }
}; */
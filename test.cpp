/* #define vi vector<int>
#define vs vector<string>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>
#define siz(v) v.size()
#define trav(v) for(auto x:v)
#define pii pair<int,int>
#define trav2(x) for(auto y:x)
#define range(v) v.begin() , v.end()
class dsu
{
private:
    /* data */
public:
int n;
int noofcomponents;
int xtraedges = 0;
vi justparent;
vi size;

dsu(int N, int C)
{
    n = N; // no.of individual nodes in graph:-
    noofcomponents = C;
    justparent.resize(n);
    for (int i = 0; i < n; i++)
        justparent[i] = i;
    size.assign(n, 1);
}

int find(int x)
{
    while (justparent[x] != x)
        x = justparent[x];
    return x;
}

bool areinsame(int nodea, int nodeb)
{
    return (find(nodea) == find(nodeb));
}

void unite(int nodea, int nodeb)
{
    // deb2(nodea, nodeb);
    if (areinsame(nodea, nodeb))
    {
        xtraedges++;
        return;
    }

    noofcomponents--;
    int c1 = find(nodea);
    int c2 = find(nodeb);
    if (size[c1] < size[c2])
        swap(c1, c2);

    size[c1] += size[c2];
    justparent[c2] = c1;
}

int sizee(int component)
{
    return size[component];
}
}
;
int x[4] = {-1, +1, 0, 0};
int y[4] = {0, 0, -1, +1};
vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q)
{
    // Write your code here.
    vvi mat(n, vi(m, 0));
    dsu d1(n * m, -1);
    int cnt = 0;
    vector<int> ans;
    trav(q)
    {
        cnt++;
        int i = x[0], j = x[1];
        int c0 = (i * m) + j;
        mat[i][j] = 1;
        for (int d = 0; d < 4; d++)
        {
            int i1 = i + x[d], j1 = j + y[d];
            if (i1 >= 0 and i1 < n and j1 >= 0 and j1 < m and mat[i1][j1] == 1)
            {
                int c = (i1 * m) + j1;
                // if (d1.areinsame(c0, c))
                // {
                //     // deb2(i1, j1);
                //     cnt--;
                // }
                // else
                // {
                d1.unite(c0, c);
                cnt--;
            }
        }
        ans.push_back(cnt);
    }
    return ans;
}
* /
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define mod 1000000007
#define inf 1e18
#define endl "\n"
#define pb push_back
#define vi vector<ll>
#define vs vector<string>
#define pii pair<ll, ll>
#define ump unordered_map
#define mp make_pair
#define pq_max priority_queue<ll>
#define pq_min priority_queue<ll, vi, greater<ll>>
#define all(n) n.begin(), n.end()
#define ff first
#define ss second
#define mid(l, r) (l + (r - l) / 2)
#define bitc(n) __builtin_popcount(n)
#define loop(i, a, b) for (int i = (a); i <= (b); i++)
#define looprev(i, a, b) for (int i = (a); i >= (b); i--)
#define iter(container, it) for (__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...)                             \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }
#define logarr(arr, a, b)            \
    for (int z = (a); z <= (b); z++) \
        cout << (arr[z]) << " ";     \
    cout << endl;
template <typename T>
T gcd(T a, T b)
{
    if (a % b)
        return gcd(b, a % b);
    return b;
}
template <typename T>
T lcm(T a, T b) { return (a * (b / gcd(a, b))); }
vs tokenizer(string str, char ch)
{
    std::istringstream var((str));
    vs v;
    string t;
    while (getline((var), t, (ch)))
    {
        v.pb(t);
    }
    return v;
}

void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << *it << " = " << a << endl;
    err(++it, args...);
}
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

void file_i_o()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

/*
Q268.) Longest Possible Route in a Matrix with Hurdles

INPUT:
1

3 10
1 1 1 1 1 1 1 1 1 1
1 1 0 1 1 0 1 1 0 1
1 1 1 1 1 1 1 1 1 1

OUTPUT:
Case #1: Length of longest possible route is 24

*/

#define R 3
#define C 10

// A Pair to store status of a cell. found is set to
// true of destination is reachable and value stores
// distance of longest path
struct Pair
{
    // true if destination is found
    bool found;

    // stores cost of longest path from current cell to
    // destination cell
    int value;
};

// Function to find Longest Possible Route in the
// matrix with hurdles. If the destination is not reachable
// the function returns false with cost INT_MAX.
// (i, j) is source cell and (x, y) is destination cell.
Pair findLongestPathUtil(int mat[R][C], int i, int j, int x,
                         int y, bool visited[R][C])
{

    // if (i, j) itself is destination, return true
    if (i == x && j == y)
    {
        Pair p = {true, 0};
        return p;
    }

    // if not a valid cell, return false
    if (i < 0 || i >= R || j < 0 || j >= C || mat[i][j] == 0 || visited[i][j])
    {
        Pair p = {false, INT_MAX};
        return p;
    }

    // include (i, j) in current path i.e.
    // set visited(i, j) to true
    visited[i][j] = true;

    // res stores longest path from current cell (i, j) to
    // destination cell (x, y)
    int res = INT_MIN;

    // go left from current cell
    Pair sol = findLongestPathUtil(mat, i, j - 1, x, y, visited);

    // if destination can be reached on going left from
    // current cell, update res
    if (sol.found)
        res = max(res, sol.value);

    // go right from current cell
    sol = findLongestPathUtil(mat, i, j + 1, x, y, visited);

    // if destination can be reached on going right from
    // current cell, update res
    if (sol.found)
        res = max(res, sol.value);

    // go up from current cell
    sol = findLongestPathUtil(mat, i - 1, j, x, y, visited);

    // if destination can be reached on going up from
    // current cell, update res
    if (sol.found)
        res = max(res, sol.value);

    // go down from current cell
    sol = findLongestPathUtil(mat, i + 1, j, x, y, visited);

    // if destination can be reached on going down from
    // current cell, update res
    if (sol.found)
        res = max(res, sol.value);

    // Backtrack
    visited[i][j] = false;

    // if destination can be reached from current cell,
    // return true
    if (res != INT_MIN)
    {
        Pair p = {true, 1 + res};
        return p;
    }

    // if destination can't be reached from current cell,
    // return false
    else
    {
        Pair p = {false, INT_MAX};
        return p;
    }
}

// A wrapper function over findLongestPathUtil()
void findLongestPath(int mat[R][C], int i, int j, int x,
                     int y)
{
    // create a boolean matrix to store info about
    // cells already visited in current route
    bool visited[R][C];

    // initialize visited to false
    memset(visited, false, sizeof visited);

    // find longest route from (i, j) to (x, y) and
    // print its maximum cost
    Pair p = findLongestPathUtil(mat, i, j, x, y, visited);
    if (p.found)
        cout << "Length of longest possible route is "
             << p.value;

    // If the destination is not reachable
    else
        cout << "Destination not reachable from given "
                "source";
}

void solve()
{
    int mat[R][C] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                     {1, 1, 0, 1, 1, 0, 1, 1, 0, 1},
                     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

    findLongestPath(mat, 0, 0, 1, 7);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    file_i_o();

    ll t = 1;
    ll case_num = 1;
    cin >> t;
    while (t--)
    {
        cout << "Case #" << case_num++ << ": ";
        solve();
    }

    return 0;
}
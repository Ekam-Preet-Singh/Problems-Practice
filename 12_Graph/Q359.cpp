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
Q359.) Cheapest Flights Within K Stops

INPUT:
2

3
0 1 100
1 2 100
0 2 500
0
2
1

3
0 1 100
1 2 100
0 2 500
0
2
0

OUTPUT:
Case #1: 200
Case #2: 500

*/

class Data
{
public:
    int node, dist, cost;
    Data(int a, int b, int c)
    {
        node = a;
        dist = b;
        cost = c;
    }
};

class Comparator
{
public:
    bool operator()(Data a, Data b)
    {
        return !(a.cost < b.cost);
    }
};

class Solution
{
public:
    vector<vector<int>> cost;
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K)
    {
        cost = vector<vector<int>>(n + 1, vector<int>(K + 10, INT_MAX));
        vector<vector<int>> graph[n];
        for (int i = 0; i < flights.size(); i++)
        {
            int u = flights[i][0];
            int v = flights[i][1];
            graph[u].push_back({v, flights[i][2]});
        }
        priority_queue<Data, vector<Data>, Comparator> q;
        q.push(Data(src, 0, 0));
        cost[src][0] = 0;
        int ans = -1;
        while (!q.empty())
        {
            Data temp = q.top();
            int curr = temp.node;
            q.pop();
            int dist = temp.dist;
            if (curr == dst)
            {
                return temp.cost;
            }
            dist++;
            if (dist > K + 1)
            {
                continue;
            }
            for (int i = 0; i < graph[curr].size(); i++)
            {
                int neighbour = graph[curr][i][0];
                if (cost[neighbour][dist] > cost[curr][dist - 1] + graph[curr][i][1])
                {
                    cost[neighbour][dist] = cost[curr][dist - 1] + graph[curr][i][1];
                    q.push(Data(neighbour, dist, cost[neighbour][dist]));
                }
            }
        }
        return -1;
    }
};

void solve()
{
    Solution ob;
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(3, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> v[i][j];
        }
    }
    int src, dst, k;
    cin >> src >> dst >> k;
    cout << (ob.findCheapestPrice(n, v, src, dst, k)) << endl;
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
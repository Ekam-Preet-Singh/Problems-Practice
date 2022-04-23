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
Q328.) Create a Graph, print it

INPUT:
1

OUTPUT:
Case #1:
0 : ( 1 , 4 ) ( 7 , 8 )
1 : ( 7 , 11 ) ( 2 , 8 )
2 : ( 8 , 2 ) ( 5 , 4 ) ( 3 , 7 )
3 : ( 3 , 14 ) ( 4 , 9 )
5 : ( 4 , 10 )
6 : ( 5 , 2 )
7 : ( 8 , 7 ) ( 6 , 1 )
8 : ( 6 , 6 )

*/

template <typename T>
class graph
{
public:
    map<T, list<pair<T, int>>> adjlist;

    void addEdge(T u, T v, int dist, bool bidirec = 1)
    {

        adjlist[u].push_back(make_pair(v, dist));

        if (bidirec)
            adjlist[v].push_back(make_pair(u, dist));
    }

    void print_adj()
    {
        for (auto n : adjlist)
        {
            cout << n.first << " : ";
            for (auto a : n.second)
            {
                cout << "( " << a.first << " , " << a.second << " ) ";
            }
            cout << endl;
        }
    }

    void bfs(T u)
    {
        map<T, bool> visited;
        queue<T> q;
        q.push(u);
        while (!q.empty())
        {
            T front_element = q.front();
            q.pop();
            if (!visited[front_element])
            {
                cout << front_element << " -> ";
                visited[front_element] = true;
            }
            for (auto a : (adjlist[front_element]))
            {
                if (!visited[a.first])
                    q.push(a.first);
            }
        }
    }

    void dfs_helper(T src, map<T, bool> &visited)
    {
        visited[src] = true;
        cout << src << " -> ";

        for (auto a : adjlist[src])
        {
            if (!visited[a.first])
            {
                dfs_helper(a.first, visited);
            }
        }
    }

    void dfs_utility(T src)
    {
        map<T, bool> visited;
        dfs_helper(src, visited);
    }

    void bfs_sssp(T src)
    {

        map<T, int> distance;
        map<T, T> parent;
        for (auto i : adjlist)
        {
            distance[i.first] = INT_MAX;
        }
        queue<T> q;
        q.push(src);
        distance[src] = 0;
        parent[src] = src;
        while (!q.empty())
        {
            T front_element = q.front();
            q.pop();

            for (auto neighbours : (adjlist[front_element]))
            {
                if (distance[neighbours.first] == INT_MAX)
                {
                    q.push(neighbours.first);
                    distance[neighbours.first] = distance[front_element] + 1;
                    parent[neighbours.first] = front_element;
                }
            }
        }

        for (auto i : adjlist)
        {
            cout << "distance to " << i.first << " from  " << src << " is " << distance[i.first] << endl;
        }
        T temp = 'g';
        while (parent[temp] != temp)
        {

            cout << temp << "<--";
            temp = parent[temp];
        }
        cout << src << endl;
    }

    void dijkstra(T src)
    {
        map<T, int> dist;
        for (auto i : adjlist)
        {
            dist[i.first] = INT_MAX;
        }
        set<pair<int, T>> s;
        s.insert(make_pair(0, src));
        dist[src] = 0;
        while (!s.empty())
        {
            auto p = *(s.begin());
            int nodedist = p.first;
            T temp = p.second;
            s.erase(s.begin());

            for (auto neigh : adjlist[temp])
            {
                if (nodedist + neigh.second < dist[neigh.first])
                {
                    auto f = s.find(make_pair(dist[neigh.first], neigh.first));
                    if (f != s.end())
                    {
                        s.erase(f);
                    }

                    dist[neigh.first] = nodedist + neigh.second;
                    s.insert(make_pair(dist[neigh.first], neigh.first));
                }
            }
        }
        for (auto d : dist)
            cout << d.first << " and " << d.second << endl;
    }
};

void solve()
{
    graph<char> g;
    g.addEdge('0', '1', 4, 0);
    g.addEdge('0', '7', 8, 0);
    g.addEdge('1', '7', 11, 0);
    g.addEdge('1', '2', 8, 0);
    g.addEdge('7', '8', 7, 0);
    g.addEdge('2', '8', 2, 0);
    g.addEdge('8', '6', 6, 0);
    g.addEdge('2', '5', 4, 0);
    g.addEdge('6', '5', 2, 0);
    g.addEdge('2', '3', 7, 0);
    g.addEdge('3', '3', 14, 0);
    g.addEdge('3', '4', 9, 0);
    g.addEdge('5', '4', 10, 0);
    g.addEdge('7', '6', 1, 0);
    g.print_adj();
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
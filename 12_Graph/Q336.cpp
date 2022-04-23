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
Q336.) Clone a graph

INPUT:
1

OUTPUT:
Case #1:
BFS Traversal before cloning
Value of Node 1
Address of Node 0x1046f10
Value of Node 2
Address of Node 0x1046f28
Value of Node 4
Address of Node 0x1046f58
Value of Node 3
Address of Node 0x1046f40

BFS Traversal after cloning
Value of Node 1
Address of Node 0x1046fb0
Value of Node 2
Address of Node 0x1048328
Value of Node 4
Address of Node 0x10483a8
Value of Node 3
Address of Node 0x1048358

*/

class Node
{
public:
    int val;
    vector<Node *> neighbours;
    Node()
    {
        val = 0;
        neighbours = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbours = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbours = _neighbors;
    }
};

class Solution
{
public:
    unordered_map<int, Node *> mp;
    Node *cloneNode(Node *_node, Node *node)
    {
        _node->val = node->val;
        mp[_node->val] = _node;

        for (Node *a : node->neighbours)
        {
            if (mp.find(a->val) == mp.end())
            {
                Node *_a = new Node();
                _a = cloneNode(_a, a);
            }
            _node->neighbours.push_back(mp[a->val]);
        }
        return _node;
    }
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return NULL;
        Node *_node = new Node();
        return cloneNode(_node, node);
    }
};

Node *buildGraph()
{
    Node *node1 = new Node();
    node1->val = 1;
    Node *node2 = new Node();
    node2->val = 2;
    Node *node3 = new Node();
    node3->val = 3;
    Node *node4 = new Node();
    node4->val = 4;
    vector<Node *> v;
    v.push_back(node2);
    v.push_back(node4);
    node1->neighbours = v;
    v.clear();
    v.push_back(node1);
    v.push_back(node3);
    node2->neighbours = v;
    v.clear();
    v.push_back(node2);
    v.push_back(node4);
    node3->neighbours = v;
    v.clear();
    v.push_back(node3);
    v.push_back(node1);
    node4->neighbours = v;
    return node1;
}

void bfs(Node *src)
{
    map<Node *, bool> visit;
    queue<Node *> q;
    q.push(src);
    visit[src] = true;
    while (!q.empty())
    {
        Node *u = q.front();
        cout << "Value of Node " << u->val << "\n";
        cout << "Address of Node " << u << "\n";
        q.pop();
        vector<Node *> v = u->neighbours;
        int n = v.size();
        for (int i = 0; i < n; i++)
        {
            if (!visit[v[i]])
            {
                visit[v[i]] = true;
                q.push(v[i]);
            }
        }
    }
    cout << endl;
}

void solve()
{
    Node *src = buildGraph();
    cout << "BFS Traversal before cloning\n";
    bfs(src);
    Solution obj;
    Node *newsrc = obj.cloneGraph(src);
    cout << "BFS Traversal after cloning\n";
    bfs(newsrc);
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
        cout << "Case #" << case_num++ << ":\n";
        solve();
    }

    return 0;
}
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
Q344.) Given a sorted Dictionary of an Alien Language, find order of characters

INPUT:
2

5 4
baa abcd abca cab cada

3 3
caa aaa aab

OUTPUT:
Case #1: 1
Case #2: 1

*/

class graph
{
public:
    int V;
    list<int> *adj;

    graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }

    void addedge(int v, int u) { adj[v].push_back(u); }
};
class Solution
{
public:
    void dictorder(string str1, string str2, graph *g, int *exist)
    {
        int n1 = str1.size();
        int n2 = str2.size();

        for (int i = 0; i < n1; i++)
        {
            exist[(int)str1[i]] = 1;
        }
        for (int i = 0; i < n2; i++)
        {
            exist[(int)str2[i]] = 1;
        }

        int i = 0;
        while (i < n1 && i < n2)
        {
            if (str1[i] != str2[i])
            {
                g->addedge((int)str1[i], (int)str2[i]);
                return;
            }
            i++;
        }
    }

    void topsort(list<int> *adj, bool *visited, stack<char> &st, int v, int *exist)
    {
        if (exist[v])
        {
            visited[v] = true;
            for (auto u : adj[v])
            {
                if (!visited[u])
                {
                    topsort(adj, visited, st, u, exist);
                }
            }
            st.push((char)v);
        }
    }

    string findOrder(string dict[], int N, int K)
    {
        graph *g = new graph(256);
        int exist[256] = {0};
        for (int i = 1; i < N; i++)
        {
            dictorder(dict[i - 1], dict[i], g, exist);
        }

        bool visited[256] = {0};
        stack<char> st;
        for (int i = 0; i < 256; i++)
        {
            if (!visited[i])
            {
                topsort(g->adj, visited, st, i, exist);
            }
        }

        string final = "";
        while (!st.empty())
        {
            final += st.top();
            st.pop();
        }

        return final;
    }
};

string order;
bool f(string a, string b)
{
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++)
    {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
    {
        return a.size() < b.size();
    }

    return p1 < p2;
}

void solve()
{

    int N, K;
    cin >> N >> K;
    string dict[N];
    for (int i = 0; i < N; i++)
        cin >> dict[i];

    Solution obj;
    string ans = obj.findOrder(dict, N, K);
    order = "";
    for (int i = 0; i < ans.size(); i++)
        order += ans[i];

    string temp[N];
    std::copy(dict, dict + N, temp);
    sort(temp, temp + N, f);

    bool f = true;
    for (int i = 0; i < N; i++)
        if (dict[i] != temp[i])
            f = false;

    if (f)
        cout << 1;
    else
        cout << 0;
    cout << endl;
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
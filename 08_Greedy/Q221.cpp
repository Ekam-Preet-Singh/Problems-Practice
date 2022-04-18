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
Q221.) Water Connection Problem

INPUT:
1

9 6
7 4 98
5 9 72
4 6 10
2 8 22
9 7 17
3 1 66

OUTPUT:
Case #1:
3
2 8 22
3 1 66
5 6 10

*/

class Solution
{
public:
    // number of houses and number
    // of pipes
    int n, p;

    // Array rd stores the
    // ending vertex of pipe
    vector<int> rd;

    // Array wd stores the value
    // of diameters between two pipes
    vector<int> wt;

    // Array cd stores the
    // starting end of pipe
    vector<int> cd;

    int ans;

    int dfs(int w)
    {
        if (cd[w] == 0)
            return w;
        if (wt[w] < ans)
            ans = wt[w];
        return dfs(cd[w]);
    }

    vector<vector<int>> solve(int n, int p, vector<int> a, vector<int> b, vector<int> d)
    {
        this->n = n;
        this->p = p;
        rd = vector<int>(n + 1);
        wt = vector<int>(n + 1);
        cd = vector<int>(n + 1);
        vector<vector<int>> res;

        int i = 0;

        while (i < p)
        {

            int q = a[i], h = b[i],
                t = d[i];

            cd[q] = h;
            wt[q] = t;
            rd[h] = q;
            i++;
        }

        for (int j = 1; j <= n; ++j)

            /*If a pipe has no ending vertex
            but has starting vertex i.e is
            an outgoing pipe then we need
            to start DFS with this vertex.*/
            if (rd[j] == 0 && cd[j])
            {
                ans = 1000000000;
                int w = dfs(j);

                // We put the details of component
                // in final output res array

                res.push_back({j, w, ans});
            }

        return res;
    }
};

void solve()
{
    int n, p;
    cin >> n >> p;
    vector<int> a(p), b(p), d(p);
    for (int i = 0; i < p; i++)
    {
        cin >> a[i] >> b[i] >> d[i];
    }
    Solution obj;
    vector<vector<int>> answer = obj.solve(n, p, a, b, d);
    cout << answer.size() << endl;
    for (auto i : answer)
    {
        cout << i[0] << " " << i[1] << " " << i[2] << endl;
    }
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
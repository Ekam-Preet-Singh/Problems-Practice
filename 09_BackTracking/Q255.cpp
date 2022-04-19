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
Q255.) Word Break Problem using Backtracking

INPUT:
2

5
cats cat and sand dog
catsanddog

5
cats cat and sand dog
catsandog

OUTPUT:
Case #1: (cat sand dog)(cats and dog)
Case #2: Empty

*/

class Solution
{
public:
    unordered_map<string, vector<string>> m;

    void combine(vector<string> &v, string w)
    {
        for (int i = 0; i < v.size(); i++)
        {
            v[i] += " " + w;
        }
    }

    vector<string> cal(string s, unordered_set<string> &mp)
    {
        if (m.find(s) != m.end())
        {
            return m[s];
        }
        vector<string> result;
        if (mp.find(s) != mp.end())
        {
            result.push_back(s);
        }
        for (int i = 1; i < s.size(); i++)
        {
            string rem = s.substr(i);
            if (mp.find(rem) != mp.end())
            {
                vector<string> v = cal(s.substr(0, i), mp);
                combine(v, rem);
                result.insert(result.end(), v.begin(), v.end());
            }
        }
        m[s] = result;
        return result;
    }

    vector<string> wordBreak(int n, vector<string> &dict, string s)
    {
        unordered_set<string> mp;
        for (int i = 0; i < n; i++)
        {
            mp.insert(dict[i]);
        }
        vector<string> ans = cal(s, mp);
        return ans;
    }
};

void solve()
{
    int n;
    vector<string> dict;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        dict.push_back(s);
    }
    cin >> s;

    Solution ob;
    vector<string> ans = ob.wordBreak(n, dict, s);
    if (ans.size() == 0)
        cout << "Empty\n";
    else
    {
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++)
            cout << "(" << ans[i] << ")";
        cout << endl;
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
        cout << "Case #" << case_num++ << ": ";
        solve();
    }

    return 0;
}
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
Q371.) Find shortest unique prefix for every word in a given list

INPUT:
3

8
the a there answer any by bye their

3
yqs iky wpv

4
zebra dog duck dove

OUTPUT:
Case #1: ans any bye thei ther
Case #2: i w y
Case #3: dog dov du z

*/

class Solution
{
#define s 26

    struct TrieNode
    {
        struct TrieNode *children[s];
        int count;
        bool end;
    };
    struct TrieNode *getNode()
    {
        struct TrieNode *node = new TrieNode;
        for (int i = 0; i < s; i++)
        {
            node->children[i] = NULL;
        }
        node->end = false;
        node->count = 0;
        return node;
    }

    void insert(TrieNode *root, string key)
    {
        struct TrieNode *temp = root;
        int len = key.length();
        for (int i = 0; i < len; i++)
        {
            if (!temp->children[key[i] - 'a'])
            {
                temp->children[key[i] - 'a'] = getNode();
            }
            temp = temp->children[key[i] - 'a'];
            temp->count++;
        }
        temp->end = true;
    }

    string search(TrieNode *root, string key)
    {
        string res;
        struct TrieNode *temp = root;
        int len = key.length();
        for (int i = 0; i < len; i++)
        {
            res.push_back(key[i]);
            temp = temp->children[key[i] - 'a'];
            if (temp->count == 1)
            {
                break;
            }
        }
        return res;
    }

    // Function to print all prefixes that uniquely
    // represent all words in arr[0..n-1]
public:
    vector<string> findPrefixes(string arr[], int n)
    {
        struct TrieNode *root = getNode();
        for (int i = 0; i < n; i++)
        {
            insert(root, arr[i]);
        }

        vector<string> res;
        for (int i = 0; i < n; i++)
        {
            res.push_back(search(root, arr[i]));
        }
        return res;
    }
};

void solve()
{
    int n;
    cin >> n;

    string arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Solution ob;
    vector<string> ans = ob.findPrefixes(arr, n);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    cout << "\n";
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
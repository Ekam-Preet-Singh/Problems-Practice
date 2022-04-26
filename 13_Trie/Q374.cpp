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
Q374.) Implement a Phone Directory

INPUT:
1

3
geeikistest geeksforgeeks geeksfortest
geeips

OUTPUT:
Case #1:
geeikistest geeksforgeeks geeksfortest
geeikistest geeksforgeeks geeksfortest
geeikistest geeksforgeeks geeksfortest
geeikistest
0
0

*/

class Solution
{
public:
    struct TrieNode
    {
        unordered_map<char, TrieNode *> child;
        bool isLast;
        TrieNode()
        {
            for (char i = 'a'; i <= 'z'; i++)
            {
                child[i] = NULL;
            }
            isLast = false;
        }
    };
    TrieNode *root = NULL;

    void insert(string s)
    {
        int len = s.length();
        TrieNode *itr = root;
        for (int i = 0; i < len; i++)
        {
            TrieNode *nextNode = itr->child[s[i]];
            if (nextNode == NULL)
            {
                nextNode = new TrieNode();
                itr->child[s[i]] = nextNode;
            }
            itr = nextNode;
            if (i == len - 1)
            {
                itr->isLast = true;
            }
        }
    }

    void insertIntoTrie(string s[], int n)
    {
        root = new TrieNode();
        for (int i = 0; i < n; i++)
        {
            insert(s[i]);
        }
    }

    void displayContactsUtil(TrieNode *curNode, string prefix, vector<string> &vec)
    {
        if (curNode->isLast)
            vec.push_back(prefix);
        for (char i = 'a'; i <= 'z'; i++)
        {
            TrieNode *nextNode = curNode->child[i];
            if (nextNode != NULL)
            {
                displayContactsUtil(nextNode, prefix + (char)i, vec);
            }
        }
    }

    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        insertIntoTrie(contact, n);
        TrieNode *prevNode = root;
        vector<vector<string>> res;
        string prefix = "";
        int len = s.length();
        int i;
        for (i = 0; i < len; i++)
        {
            vector<string> v;
            prefix += (char)s[i];
            char lastChar = prefix[i];
            TrieNode *curNode = prevNode->child[lastChar];
            if (curNode == NULL)
            {
                v.push_back("0");
                res.push_back(v);
                i++;
                break;
            }
            displayContactsUtil(curNode, prefix, v);
            prevNode = curNode;
            res.push_back(v);
        }
        for (; i < len; i++)
        {
            vector<string> v;
            v.push_back("0");
            res.push_back(v);
        }
        return res;
    }
};

void solve()
{
    int n;
    cin >> n;
    string contact[n], s;
    for (int i = 0; i < n; i++)
        cin >> contact[i];
    cin >> s;

    Solution ob;
    vector<vector<string>> ans = ob.displayContacts(n, contact, s);
    for (int i = 0; i < s.size(); i++)
    {
        for (auto u : ans[i])
            cout << u << " ";
        cout << "\n";
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
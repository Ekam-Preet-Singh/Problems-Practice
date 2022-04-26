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
Q372.) Word Break Problem | (Trie solution)

INPUT:
3

10
scd rjmowfrx jybldbe sarcbyne dyggxxp lorel nmpa qfwkho kmcoqhnw kuewhsqmgb dyggxxp

12
i like sam sung samsung mobile ice cream icecream man go mango ilike

4
lrbbmqb cd r owkk lrbbmqbabowkkab

OUTPUT:
Case #1: 1
Case #2: 1
Case #3: 0

*/

const int ALPHABET_SIZE = 26;

// trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];

    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = new TrieNode;

    pNode->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        pNode->children[i] = NULL;
    }

    return pNode;
}
class Solution
{
public:
    // If not present, inserts key into trie
    // If the key is prefix of trie node, just
    // marks leaf node
    void insert(struct TrieNode *root, string key)
    {
        struct TrieNode *pCrawl = root;

        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'a';
            if (!pCrawl->children[index])
            {
                pCrawl->children[index] = getNode();
            }

            pCrawl = pCrawl->children[index];
        }

        // mark last node as leaf
        pCrawl->isEndOfWord = true;
    }

    // Returns true if key presents in trie, else
    // false
    bool search(struct TrieNode *root, string key)
    {
        struct TrieNode *pCrawl = root;

        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'a';
            if (!pCrawl->children[index])
            {
                return false;
            }

            pCrawl = pCrawl->children[index];
        }

        return (pCrawl != NULL && pCrawl->isEndOfWord);
    }

    // returns true if string can be segmented into
    // space separated words, otherwise returns false
    bool wordBreakutil(string const &str, TrieNode *root)
    {
        int size = str.size();

        // Base case
        if (size == 0)
        {
            return true;
        }

        // Try all prefixes of lengths from 1 to size
        for (int i = 1; i <= size; i++)
        {
            // The parameter for search is str.substr(0, i)
            // str.substr(0, i) which is prefix (of input
            // string) of length 'i'. We first check whether
            // current prefix is in dictionary. Then we
            // recursively check for remaining string
            // str.substr(i, size-i) which is suffix of
            // length size-i
            if (search(root, str.substr(0, i)) && wordBreakutil(str.substr(i, size - i), root))
            {
                return true;
            }
        }

        // If we have tried all prefixes and none
        // of them worked
        return false;
    }

    int wordBreak(string A, vector<string> &B)
    {
        // code here
        struct TrieNode *root = getNode();

        // Construct trie
        for (int i = 0; i < B.size(); i++)
        {
            insert(root, B[i]);
        }

        return wordBreakutil(A, root) ? 1 : 0;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<string> dict;
    for (int i = 0; i < n; i++)
    {
        string S;
        cin >> S;
        dict.push_back(S);
    }
    string line;
    cin >> line;
    Solution ob;
    cout << ob.wordBreak(line, dict) << "\n";
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
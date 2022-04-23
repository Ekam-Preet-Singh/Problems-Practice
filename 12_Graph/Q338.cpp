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
Q338.) word Ladder

INPUT:
2

6
hit cog
hot dot dog lot log cog

5
hit cog
hot dot dog lot log

OUTPUT:
Case #1: 5
Case #2: 0

*/

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        if (beginWord.size() != endWord.size())
        {
            return 0; // if the length of beginWord & endWord is not same, no chance of reaching (Base case 1)
        }
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> q;
        if (!dict.count(endWord))
        {
            return 0; // if the endWord is not in the wordList, there is no chance of reaching  (Base case 2)
        }
        q.push(beginWord);
        int ladderCount = 1;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                string word = q.front();
                q.pop();
                if (word == endWord)
                {
                    return ladderCount;
                }
                dict.erase(word);
                for (int j = 0; j < word.size(); j++)
                {
                    char temp = word[j];
                    for (int k = 0; k < 26; k++)
                    {
                        word[j] = 'a' + k;
                        if (dict.count(word))
                        {
                            q.push(word);
                        }
                    }
                    word[j] = temp;
                }
            }
            ladderCount++;
        }
        return 0;
    }
};

void solve()
{
    string beginWord, endWord;
    int n;
    vector<string> wordList(n, "");
    cin >> n >> beginWord >> endWord;
    for (int i = 0; i < n; i++)
    {
        cin >> wordList[i];
    }
    Solution obj;
    cout << obj.ladderLength(beginWord, endWord, wordList) << endl;
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
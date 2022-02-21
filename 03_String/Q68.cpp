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
Q68.) Count of number of given string in 2D character array

INPUT:
4

6 6
D D D G D D
B B D E B S
B S K E B K
D D D D D E
D D D D D E
D D D D D G
GEEKS

6 6
B B M B B B
C B A B B B
I B G B B B
G B I B B B
A B C B B B
M C I G A M
MAGIC

4 5
S N B S N
B A K E A
B K B B K
S E B S E
SNAKES

3 3
c a t
a t c
c t a
cat

OUTPUT:
Case #1: 2
Case #2: 4
Case #3: 3
Case #4: 5

*/

class Solution
{
public:
    int findPath(vector<vector<char>> mat, string target, int startX, int startY, int targetIndex)
    {

        if (startX < 0 || startY < 0 || startX >= mat.size() || startY >= mat[startX].size())
        {
            return 0;
        }

        char original = mat[startX][startY];

        if (original != target[targetIndex])
        {
            return 0;
        }

        if (targetIndex == target.size() - 1)
        {
            return 1;
        }

        int count = 0;
        mat[startX][startY] = '\0'; // avoid return back to visited node

        count += findPath(mat, target, startX + 1, startY, targetIndex + 1);
        count += findPath(mat, target, startX, startY + 1, targetIndex + 1);
        count += findPath(mat, target, startX - 1, startY, targetIndex + 1);
        count += findPath(mat, target, startX, startY - 1, targetIndex + 1);

        mat[startX][startY] = original;
        return count;
    }

    int findOccurrence(vector<vector<char>> &mat, string target)
    {
        int count = 0;
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[i].size(); j++)
            {
                count += findPath(mat, target, i, j, 0);
            }
        }
        return count;
    }
};

void solve()
{
    int R, C;
    cin >> R >> C;
    vector<vector<char>> mat(R);
    for (int i = 0; i < R; i++)
    {
        mat[i].resize(C);
        for (int j = 0; j < C; j++)
            cin >> mat[i][j];
    }
    string target;
    cin >> target;
    Solution obj;
    cout << obj.findOccurrence(mat, target) << endl;
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
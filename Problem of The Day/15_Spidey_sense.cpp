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

class Solution
{
    struct QueueNode
    {
        int i, j, distance;
    };
    bool isValid(int i, int j, int M, int N)
    {
        if ((i < 0 || i > M - 1) || (j < 0 || j > N - 1))
            return false;

        return true;
    }

    bool isSafe(int i, int j, vector<vector<char>> &matrix, vector<vector<int>> &result)
    {
        if (matrix[i][j] != 'O' || result[i][j] != -1)
            return false;

        return true;
    }

public:
    vector<vector<int>> findDistance(vector<vector<char>> &matrix, int M, int N)
    {
        vector<vector<int>> result(M);
        queue<QueueNode> q;

        for (int i = 0; i < M; i++)
        {
            result[i].resize(N, -1);
            for (int j = 0; j < N; j++)
            {
                if (matrix[i][j] == 'B')
                {
                    QueueNode node = {i, j, 0};
                    q.push(node);
                    result[i][j] = 0;
                }
            }
        }

        while (!q.empty())
        {
            QueueNode curr = q.front();
            int x = curr.i, y = curr.j, dist = curr.distance;

            int row[] = {-1, 0, 1, 0};
            int col[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++)
            {
                if (isValid(x + row[i], y + col[i], M, N) &&
                    isSafe(x + row[i], y + col[i], matrix, result))
                {
                    result[x + row[i]][y + col[i]] = dist + 1;

                    QueueNode node = {x + row[i], y + col[i], dist + 1};
                    q.push(node);
                }
            }

            q.pop();
        }
        return result;
    }
};

void solve()
{
    int M, N;
    cin >> M;
    cin >> N;

    vector<vector<char>> matrix(M);
    for (int i = 0; i < M; ++i)
    {
        matrix[i].resize(N);
        for (int j = 0; j < N; ++j)
            cin >> matrix[i][j];
    }

    vector<vector<int>> result;
    Solution obj;
    result = obj.findDistance(matrix, M, N);
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
            cout << result[i][j] << " ";
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
    // ll case_num = 1;
    cin >> t;
    while (t--)
    {
        // cout << "Case #" << case_num++ << ": ";
        solve();
    }

    return 0;
}
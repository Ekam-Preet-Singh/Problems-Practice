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
Q334.) Minimum Step by Knight

INPUT:
2

6
4 5
1 1

3
3 3
2 1

OUTPUT:
Case #1: 3
Case #2: 1

*/

class Solution
{
private:
    struct cell
    {
        int x;
        int y;
        int steps;
    };

public:
    // Function to check if cell indexes are within bounds.
    bool isValid(int x, int y, int N)
    {
        return (x >= 0 and x < N and y >= 0 and y < N);
    }

    // Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
    {
        KnightPos[0]--;
        KnightPos[1]--;
        TargetPos[0]--;
        TargetPos[1]--;

        // using boolean list to mark visited cells and currently
        // marking all the cells as false.
        vector<vector<bool>> vis(N, vector<bool>(N, false));

        vector<vector<int>> dxy = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

        // queue for storing visited cells by knight in board and steps taken.
        queue<cell> q;

        // pushing starting position of knight with 0 distance.
        q.push({KnightPos[0], KnightPos[1], 0});

        // marking starting cell as visited.
        vis[KnightPos[0]][KnightPos[1]] = true;

        while (!q.empty())
        {
            // storing cell indexes and steps of front element and popping them.
            int x = q.front().x;
            int y = q.front().y;
            int steps = q.front().steps;
            q.pop();

            // if we reach the required cell, we return true.
            if (x == TargetPos[0] and y == TargetPos[1])
            {
                return steps;
            }

            // using loop to reach all the cells that can be reached by knight.
            for (int i = 0; i < dxy.size(); i++)
            {
                int n_x = x + dxy[i][0];
                int n_y = y + dxy[i][1];

                // if cell indexes are valid and cell is not visited, we push the
                // indexes in queue with steps and mark cell as visited.
                if (isValid(n_x, n_y, N) and !vis[n_x][n_y])
                {
                    q.push({n_x, n_y, steps + 1});
                    vis[n_x][n_y] = true;
                }
            }
        }
        return -1;
    }
};

void solve()
{
    vector<int> KnightPos(2);
    vector<int> TargetPos(2);
    int N;
    cin >> N;
    cin >> KnightPos[0] >> KnightPos[1];
    cin >> TargetPos[0] >> TargetPos[1];
    Solution obj;
    int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
    cout << ans << "\n";
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
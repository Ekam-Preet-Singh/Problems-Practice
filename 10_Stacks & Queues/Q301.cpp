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
Q301.) Find the first circular tour that visits all Petrol Pumps

INPUT:
2

4
4 6 6 5 7 3 4 5

8
96 25 46 83 68 15 65 35 51 44 9 88 79 77 85 89

OUTPUT:
Case #1: 1
Case #2: 0

*/

struct petrolPump
{
    int petrol;
    int distance;
};

class Solution
{
public:
    // Function to find starting point where the truck can start to get through
    // the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[], int n)
    {
        // considering first petrol pump as a starting point.
        int start = 0;
        int end = 1;
        int cur_pet = p[start].petrol - p[start].distance;

        // we run a loop while all petrol pumps are not visited and we have
        // reached first petrol pump again with 0 or more petrol.
        while (end != start or cur_pet < 0)
        {
            // if current amount of petrol in truck becomes less than 0,
            // then remove the starting petrol pump from tour.
            while (cur_pet < 0 and start != end)
            {
                // removing starting petrol pump and changing starting point.
                cur_pet -= p[start].petrol - p[start].distance;
                start = (start + 1) % n;

                // if 0 is being considered as start again, then there
                // is no possible solution.
                if (start == 0)
                    return -1;
            }
            // adding a petrol pump to current tour.
            cur_pet += p[end].petrol - p[end].distance;
            end = (end + 1) % n;
        }
        // returning starting point.
        return start;
    }
};

void solve()
{
    int n;
    cin >> n;
    petrolPump p[n];
    for (int i = 0; i < n; i++)
        cin >> p[i].petrol >> p[i].distance;
    Solution obj;
    cout << obj.tour(p, n) << endl;
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
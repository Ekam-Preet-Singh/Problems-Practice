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
Q94.) Optimum location of point to minimize total distance

INPUT:
2

1 -1 -3
5 2
-3 -2
-1 0
-1 2
1 2
3 4

1 -1 -3
6 2
2 3
12 30
40 50
5 1
12 10
3 4

OUTPUT:
Case #1: 20.7652
Case #2: 103.336

*/

#define sq(x) ((x) * (x))
#define EPS 1e-6

//  structure defining a point
class point
{
public:
    int x, y;
    point() {}
    point(int x, int y)
        : x(x), y(y)
    {
    }
};

//  structure defining a line of ax + by + c = 0 form
class line
{
public:
    int a, b, c;
    line(int a, int b, int c)
        : a(a), b(b), c(c)
    {
    }
};

//  method to get distance of point (x, y) from point p
double dist(double x, double y, point p)
{
    return sqrt(sq(x - p.x) + sq(y - p.y));
}

/*  Utility method to compute total distance all points
    when choose point on given line has x-coordinate
    value as X   */

double compute(point p[], int n, line l, double X)
{
    double res = 0;
    //  calculating Y of chosen point by line equation
    double Y = -1 * (l.c + l.a * X) / l.b;
    for (int i = 0; i < n; i++)
    {
        res += dist(X, Y, p[i]);
    }

    return res;
}

//  Utility method to find minimum total distance
double findOptimumCostUtil(point p[], int n, line l)
{
    double low = -1e6;
    double high = 1e6;

    // loop until difference between low and high
    // become less than EPS
    while ((high - low) > EPS)
    {
        // mid1 and mid2 are representative x co-ordiantes
        // of search space
        double mid1 = low + (high - low) / 3;
        double mid2 = high - (high - low) / 3;

        double dist1 = compute(p, n, l, mid1);
        double dist2 = compute(p, n, l, mid2);

        // if mid2 point gives more total distance,
        // skip third part
        if (dist1 < dist2)
        {
            high = mid2;
        }
        // if mid1 point gives more total distance,
        // skip first part
        else
        {
            low = mid1;
        }
    }

    // compute optimum distance cost by sending average
    // of low and high as X
    return compute(p, n, l, (low + high) / 2);
}

//  method to find optimum cost
double findOptimumCost(int **points, int n, int k, line l)
{
    point p[n];
    //  converting 2D array input to point array
    for (int i = 0; i < n; i++)
    {
        p[i] = point(points[i][0], points[i][1]);
    }

    return findOptimumCostUtil(p, n, l);
}

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    line l(a, b, c);

    int n, k;
    cin >> n >> k;

    int **points = new int *[n];
    for (int i = 0; i < n; i++)
        points[i] = new int[k];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
            cin >> points[i][j];

    cout << findOptimumCost(points, n, k, l) << endl;
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
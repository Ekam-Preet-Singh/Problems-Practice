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
Q136.) Intersection Point of two Linked Lists.

INPUT:
2

3 1 2
3 6 9
10
15 30

2 3 3
4 1
5 6 1
8 4 5

OUTPUT:
Case #1: 15
Case #2: 8

*/

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *inputList(int size)
{
    if (size == 0)
    {
        return NULL;
    }

    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

// Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node *head1, Node *head2)
{
    int n1 = 0, n2 = 0;
    Node *temp;

    // finding length of list1.
    for (temp = head1; temp; temp = temp->next)
    {
        n1++;
    }

    // finding length of list2.
    for (temp = head2; temp; temp = temp->next)
    {
        n2++;
    }

    // if list1 is longer, we ignore some of its starting
    // elements till it has as many elements as list2.
    for (; n1 > n2; n1--)
    {
        head1 = head1->next;
    }

    // similarly, if list2 is longer, we ignore some of its starting
    // elements till it has as many elements as list1.
    for (; n2 > n1; n2--)
    {
        head2 = head2->next;
    }

    // now we simply traverse ahead till we get the intersection point, if there
    // is none, this loop will break when both pointers point at NULL.
    while (head1 != head2)
    {
        head1 = head1->next;
        head2 = head2->next;
    }

    // if head1 is not NULL, we return its data otherwise we return -1.
    if (head1)
    {
        return head1->data;
    }
    return -1;
}

void solve()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    Node *head1 = inputList(n1);
    Node *head2 = inputList(n2);
    Node *common = inputList(n3);

    Node *temp = head1;
    while (temp != NULL && temp->next != NULL)
        temp = temp->next;
    if (temp != NULL)
        temp->next = common;

    temp = head2;
    while (temp != NULL && temp->next != NULL)
        temp = temp->next;
    if (temp != NULL)
        temp->next = common;

    cout << intersectPoint(head1, head2) << endl;
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
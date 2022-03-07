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
Q137.) Merge Sort For Linked lists.[Very Important]

INPUT:
6

5 
1 2 3 6 9

2
15 30

4
3 3 4 1

5 
6 1 8 4 5

5
5 4 3 2 1

3
9 15 0

OUTPUT:
Case #1: 1 2 3 6 9 
Case #2: 15 30 
Case #3: 1 3 3 4 
Case #4: 1 4 5 6 8 
Case #5: 1 2 3 4 5 
Case #6: 0 9 15 

*/

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

class Solution
{
public:
    // Function to split the list into two halves.
    void splitList(Node *source, Node **frontRef, Node **backRef)
    {

        // using two pointers to find the midpoint of list.
        struct Node *fast;
        struct Node *slow;
        if (source == NULL || source->next == NULL)
        {
            *frontRef = source;
            *backRef = NULL;
        }
        else
        {
            // first pointer, slow moves 1 node and second pointer, fast moves
            // 2 nodes in one iteration.
            slow = source;
            fast = source->next;
            while (fast != NULL)
            {
                fast = fast->next;
                if (fast != NULL)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
            }

            // slow is before the midpoint in the list, so we split the
            // list in two halves from that point.
            *frontRef = source;
            *backRef = slow->next;
            slow->next = NULL;
        }
    }

    // Function to merge two halves of list.
    Node *mergeList(struct Node *a, struct Node *b)
    {
        struct Node *result = NULL;

        // base cases when either of two halves is null.
        if (a == NULL)
        {
            return (b);
        }
        else if (b == NULL)
        {
            return (a);
        }

        // comparing data in both halves and storing the smaller in result and
        // recursively calling the mergeList function for next node in result.
        if (a->data <= b->data)
        {
            result = a;
            result->next = mergeList(a->next, b);
        }
        else
        {
            result = b;
            result->next = mergeList(a, b->next);
        }
        // returning the resultant list.
        return (result);
    }

    // Function to sort the given linked list using Merge Sort.
    Node *mergeSort(Node *head)
    {

        struct Node *a;
        struct Node *b;

        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        // splitting the list into two halves.
        splitList(head, &a, &b);

        // calling the mergeSort function recursively for both parts separately.
        a = mergeSort(a);
        b = mergeSort(b);

        // calling the function to merge both halves.
        return mergeList(a, b);
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

void push(struct Node **head_ref, int new_data)
{
    Node *new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void solve()
{
    struct Node *a = NULL;
    long n, tmp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        push(&a, tmp);
    }
    Solution obj;
    a = obj.mergeSort(a);
    printList(a);
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
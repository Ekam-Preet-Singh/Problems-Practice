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
Q133.) Add “1” to a number represented as a Linked List.

INPUT:
9

5224

22222

5224

12345

19999

292920

12345

62782927

33743939389487329947093899

OUTPUT:
Case #1: 5225
Case #2: 22223
Case #3: 5225
Case #4: 12346
Case #5: 20000
Case #6: 292921
Case #7: 12346
Case #8: 62782928
Case #9: 33743939389487329947093900

*/

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data;
        node = node->next;
    }
    cout << "\n";
}

class Solution
{

public:
    Node *reverse(Node *head)
    {
        Node *prev = NULL;
        Node *current = head;
        Node *next;

        while (current != NULL)
        {
            next = current->next; // storing next node
            current->next = prev; // linking current node to previous
            prev = current;       // updating prev
            current = next;       // updating current
        }

        return prev;
    }
    Node *addOne(Node *head)
    {
        head = reverse(head); // reversing list to make addition easy

        Node *current = head;
        int carry = 1;

        while (carry)
        {
            current->data += 1; // adding one to current node

            if (current->data < 10)
            {
                return reverse(head);
            }
            // if no carry we can reverse back list and return it
            else
            {
                current->data = 0;
            }
            // else we continue with taking carry forward
            if (current->next == NULL)
            {
                break;
            }
            // if, end of list, we break from loop
            else
            {
                current = current->next;
            }
            // else we move to next node
        }

        current->next = new Node(1); // adding new node for the carried 1
        return reverse(head);
    }
};

void solve()
{
    string s;
    cin >> s;

    Node *head = new Node(s[0] - '0');
    Node *tail = head;
    for (int i = 1; i < s.size(); i++)
    {
        tail->next = new Node(s[i] - '0');
        tail = tail->next;
    }
    Solution ob;
    head = ob.addOne(head);
    printList(head);
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
#pragma GCC optimize("Ofast,unroll-loops")

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_set;

#define ll long long
#define ld long double
#define u unsigned

#define PB push_back
#define MP make_pair

#define LPI(i, a, b, d) for (int i{a}; i < b; i += d)
#define LPD(i, a, b, d) for (int i{a}; i < b; i -= d)

#ifndef INT_MAX
#define INT_MAX 2147483647
#endif
#ifndef INT_MIN
#define INT_MIN -2147483648
#endif
#define LL_MIN -9223372036854775808
#define LL_MAX 9223372036854775807

using VI = vector<int>;
using VVI = vector<VI>;
using VS = vector<string>;
using VVS = vector<VS>;
using PI = pair<int, int>;
using TI = tuple<int, int, int>;

#define ZEROS_B(x) __builtin_clz(x)
#define ZEROS_E(x) __builtin_ctz(x)

constexpr double pi = acos(-1);
constexpr int mod = 998244353;
constexpr double eps = 1e-10;
constexpr int N = 1e2 + 10;

template <typename T>
T gcd(T a, T b) {
    if (!a || !b) return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b) swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}

template <typename T>
T LCM(T a, T b) {
    return a / GCD(a, b) * b;
}

struct Node {
    int key;
    vector<Node*> children;
    Node* parent;
};

class rtree {
   private:
    Node* root;
    int size;

   public:
    rtree() {
        size = 0;
        auto node = new Node;
        node->parent = NULL;
        node->children = vector<Node*>{};
        node->key = ++size;
        root = node;
    }

    void insert(int index) {
        auto node = new Node;
        node->parent = NULL;
        node->children = vector<Node*>{};
        node->key = ++size;
        auto nd = bfs(index);
        nd->children.PB(node);
        node->parent = nd;
    }

    bool szukaj() {
        auto node{root};
        if(!scan(node->children)) return false;
        stack<Node*> st;
        if (node->children.size() > 0) {
            for (int i = 0; i < node->children.size(); ++i) {
                st.push(node->children[i]);
            }
        }
        while (st.size() > 0) {
            auto current{st.top()};
            st.pop();
            if (current->children.size() > 0) {
                for (int i = 0; i < current->children.size(); ++i) {
                    st.push(current->children[i]);
                }
            }
            if (current->children.size() > 0 && current->parent != NULL) {
                if (!scan(current->children)) return false;
            }
        }
        return true;
    }

    Node* bfs(int val) {
        auto node{root};
        queue<Node*> qq;
        qq.push(node);
        while (qq.size() > 0) {
            auto current{qq.front()};
            if (current->key == val) {
                return current;
            }
            qq.pop();
            if (current->children.size() > 0) {
                for (int i = 0; i < current->children.size(); ++i) {
                    qq.push(current->children[i]);
                }
            }
        }
    }

    bool scan(const vector<Node*> ch) {
        int leaf = 0;
        LPI(i, 0, ch.size(), 1) {
            if (ch[i]->children.size() == 0) ++leaf;
        }
        return leaf == 3 ? true : false;
    }
};

auto main() -> int {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

#ifndef ONLINE_JUDGE
    clock_t begin = clock();
#endif

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    auto drzewko = rtree();
    bool cool = false;
    LPI(i, 0, n - 1, 1) {
        int in;
        cin >> in;
        drzewko.insert(in);
    }
    drzewko.szukaj() ? cout << "Yes" : cout << "No";

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000
         << " ms\n";
#endif

    return 0;
}

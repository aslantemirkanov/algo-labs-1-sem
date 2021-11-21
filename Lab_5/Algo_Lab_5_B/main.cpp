#include <iostream>

using namespace std;

int is_tree = 1;
long long global_min = -1000000001;
long long global_max = 1000000001;

struct tree_item {
    long long key;
    long long right_child;
    long long left_child;
};

void check(struct tree_item *bin_tree, long long cur_item, long long min, long long max) {

    if (bin_tree[cur_item].key <= min || bin_tree[cur_item].key >= max) {
        is_tree = 0;
        return;
    }

    if (bin_tree[cur_item].right_child == -1 && bin_tree[cur_item].left_child == -1) return;

    if (bin_tree[cur_item].left_child >= 0) {
        check(bin_tree, bin_tree[cur_item].left_child, min, bin_tree[cur_item].key);
    }

    if (bin_tree[cur_item].right_child >= 0) {
        check(bin_tree, bin_tree[cur_item].right_child, bin_tree[cur_item].key, max);
    }

}

int main() {

    /*freopen("check.in", "r", stdin);
    freopen("check.out", "w", stdout);*/

    long long n, cur_item = 0;

    cin >> n;
    struct tree_item bin_tree[n];

    if (n == 0) {
        cout << "YES";
        return 0;
    }

    for (long long i = 0; i < n; i++) {
        cin >> bin_tree[i].key >> bin_tree[i].left_child >> bin_tree[i].right_child;
        bin_tree[i].left_child--;
        bin_tree[i].right_child--;
    }

    check(bin_tree, cur_item, global_min, global_max);

    is_tree ? (cout << "YES") : (cout << "NO");

    return 0;
}
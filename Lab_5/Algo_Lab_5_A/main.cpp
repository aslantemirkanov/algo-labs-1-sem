#include <bits/stdc++.h>

using namespace std;

long long max_height = 0;

struct tree_item {
    long long right_child;
    long long left_child;
};

void tree_height(struct tree_item *bin_tree, long long cur_item, long long cur_height) {

    max_height = max(max_height, cur_height);

    if (bin_tree[cur_item].left_child >= 0) {
        tree_height(bin_tree, bin_tree[cur_item].left_child, cur_height + 1);
    }

    if (bin_tree[cur_item].right_child >= 0) {
        tree_height(bin_tree, bin_tree[cur_item].right_child, cur_height + 1);
    }

}

int main() {

    freopen("height.in", "r", stdin);
    freopen("height.out", "w", stdout);

    long long n, cur_height = 1, cur_item = 0, key;

    cin >> n;
    struct tree_item bin_tree[n];

    if (n == 0) {
        cout << 0;
    } else {

        for (long long i = 0; i < n; i++) {
            cin >> key >> bin_tree[i].left_child >> bin_tree[i].right_child;
            bin_tree[i].left_child--;
            bin_tree[i].right_child--;
        }

        tree_height(bin_tree, cur_item, cur_height);
        cout << max_height;

    }
    return 0;
}
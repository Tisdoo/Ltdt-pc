#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include<algorithm>
using namespace std;

#define FI "Bai2.inp"
#define FO "Bai2.out"

int n, x, y;
vector<set<int>> adjlist;
vector<bool> visited;
vector<int> parent;

bool DFS(int u, int target) {
    visited[u] = true;
    if (u == target) return true; // tìm thấy y

    for (set<int>::iterator it = adjlist[u].begin();
         it != adjlist[u].end(); ++it) {
        int v = *it;
        if (!visited[v]) {
            parent[v] = u;
            if (DFS(v, target)) return true;
        }
    }
    return false;
}

void solve() {
    char line[1000];
    int v;

    cin >> n >> x >> y;
    cin.ignore(1000, '\n');

    adjlist.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin.getline(line, 1000);
        stringstream sline(line);
        while (sline >> v) {
            adjlist[i].insert(v);
        }
    }

    visited.assign(n + 1, false);
    parent.assign(n + 1, -1);

    if (!DFS(x, y)) {
        cout << "-1\n"; // không có đường đi
        return;
    }

    // truy vết đường đi từ y về x
    vector<int> path;
    for (int cur = y; cur != -1; cur = parent[cur]) {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    for (int u : path) cout << u << " ";
    cout << "\n";
}

int main() {
    freopen(FI, "rt", stdin);
    freopen(FO, "wt", stdout);
    solve();
    return 0;
}

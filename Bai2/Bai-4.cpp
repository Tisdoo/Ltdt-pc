#include <iostream>
#include <vector>
using namespace std;

#define FI "DanhSachCanh.inp"
#define FO "DanhSachCanh.out"

int n, m;
vector<int> deg;

void solve() {
    // Đọc số đỉnh và số cạnh
    cin >> n >> m;
    deg.assign(n + 1, 0);

    // Đọc m cạnh và cập nhật bậc
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        deg[u]++;   // mỗi cạnh tăng bậc 2 đỉnh
        deg[v]++;
    }

    // Xuất kết quả
    cout << n << endl;
    for (int i = 1; i <= n; i++) {
        cout << deg[i] << endl;
    }
}

int main() {
    freopen(FI, "r", stdin);
    freopen(FO, "w", stdout);
    solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> Matrix;
typedef vector<vector<int>> AdjList;
typedef vector<pair<int,int>> EdgeList;

// 1. Ma trận kề -> Danh sách kề
AdjList matrixToList(const Matrix &mat) {
    int n = mat.size();
    AdjList adj(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]) adj[i].push_back(j);
        }
    }
    return adj;
}

// 2. Ma trận kề -> Danh sách cạnh
EdgeList matrixToEdges(const Matrix &mat) {
    int n = mat.size();
    EdgeList edges;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]) edges.push_back({i,j});
        }
    }
    return edges;
}

// 3. Danh sách kề -> Ma trận kề
Matrix listToMatrix(const AdjList &adj) {
    int n = adj.size();
    Matrix mat(n, vector<int>(n,0));
    for(int u=0;u<n;u++){
        for(int v:adj[u]){
            mat[u][v] = 1;
        }
    }
    return mat;
}

// 4. Danh sách kề -> Danh sách cạnh
EdgeList listToEdges(const AdjList &adj) {
    EdgeList edges;
    for(int u=0;u<adj.size();u++){
        for(int v:adj[u]){
            edges.push_back({u,v});
        }
    }
    return edges;
}

// 5. Danh sách cạnh -> Ma trận kề
Matrix edgesToMatrix(const EdgeList &edges, int n) {
    Matrix mat(n, vector<int>(n,0));
    for(auto [u,v]:edges){
        mat[u][v] = 1;
    }
    return mat;
}

// 6. Danh sách cạnh -> Danh sách kề
AdjList edgesToList(const EdgeList &edges, int n) {
    AdjList adj(n);
    for(auto [u,v]:edges){
        adj[u].push_back(v);
    }
    return adj;
}

// Hàm in thử
void printMatrix(const Matrix &mat) {
    for(auto &row:mat){
        for(int x:row) cout << x << " ";
        cout << "\n";
    }
}

void printAdjList(const AdjList &adj) {
    for(int i=0;i<adj.size();i++){
        cout << i << ": ";
        for(int v:adj[i]) cout << v << " ";
        cout << "\n";
    }
}

void printEdges(const EdgeList &edges) {
    for(auto [u,v]:edges) cout << "("<<u<<","<<v<<") ";
    cout << "\n";
}

int main() {
    // Ví dụ ma trận kề (đồ thị có 4 đỉnh)
    Matrix mat = {
        {0,1,1,0},
        {0,0,1,0},
        {0,0,0,1},
        {1,0,0,0}
    };

    cout << "Ma tran ke -> Danh sach ke:\n";
    AdjList adj = matrixToList(mat);
    printAdjList(adj);

    cout << "\nMa tran ke -> Danh sach canh:\n";
    EdgeList edges = matrixToEdges(mat);
    printEdges(edges);

    cout << "\nDanh sach ke -> Ma tran ke:\n";
    printMatrix(listToMatrix(adj));

    cout << "\nDanh sach ke -> Danh sach canh:\n";
    printEdges(listToEdges(adj));

    cout << "\nDanh sach canh -> Ma tran ke:\n";
    printMatrix(edgesToMatrix(edges, 4));

    cout << "\nDanh sach canh -> Danh sach ke:\n";
    printAdjList(edgesToList(edges, 4));
}

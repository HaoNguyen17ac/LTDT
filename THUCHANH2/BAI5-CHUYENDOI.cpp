#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int> > AdjMatrix;
typedef vector< vector<int> > AdjList;
typedef vector< pair<int, int> > EdgeList;

// 1. Ma trận kề → Danh sách kề 
AdjList matrixToList(const AdjMatrix& matrix) {
    int n = matrix.size();
    AdjList list(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (matrix[i][j])
                list[i].push_back(j);
    return list;
}

// 2. Ma trận kề → Danh sách cạnh 
EdgeList matrixToEdges(const AdjMatrix& matrix) {
    EdgeList edges;
    for (int i = 0; i < matrix.size(); ++i)
        for (int j = 0; j < matrix[i].size(); ++j)
            if (matrix[i][j])
                edges.push_back(make_pair(i, j));
    return edges;
}

// 3. Danh sách kề → Ma trận kề 
AdjMatrix listToMatrix(const AdjList& list) {
    int n = list.size();
    AdjMatrix matrix(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int k = 0; k < list[i].size(); ++k)
            matrix[i][list[i][k]] = 1;
    return matrix;
}

// 4. Danh sách kề → Danh sách cạnh
EdgeList listToEdges(const AdjList& list) {
    EdgeList edges;
    for (int i = 0; i < list.size(); ++i)
        for (int k = 0; k < list[i].size(); ++k)
            edges.push_back(make_pair(i, list[i][k]));
    return edges;
}

// 5. Danh sách cạnh → Ma trận kề 
AdjMatrix edgesToMatrix(const EdgeList& edges, int n) {
    AdjMatrix matrix(n, vector<int>(n, 0));
    for (int i = 0; i < edges.size(); ++i)
        matrix[edges[i].first][edges[i].second] = 1;
    return matrix;
}

// 6. Danh sách cạnh → Danh sách kề
AdjList edgesToList(const EdgeList& edges, int n) {
    AdjList list(n);
    for (int i = 0; i < edges.size(); ++i)
        list[edges[i].first].push_back(edges[i].second);
    return list;
}

void printMatrix(const AdjMatrix& matrix) {
    cout << "Ma trận kề:\n";
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
}

void printList(const AdjList& list) {
    cout << "Danh sách kề:\n";
    for (int i = 0; i < list.size(); ++i) {
        cout << i << ": ";
        for (int j = 0; j < list[i].size(); ++j)
            cout << list[i][j] << " ";
        cout << "\n";
    }
}

void printEdges(const EdgeList& edges) {
    cout << "Danh sách cạnh:\n";
    for (int i = 0; i < edges.size(); ++i)
        cout << "(" << edges[i].first << ", " << edges[i].second << ")\n";
}


int main() {
    int n = 3;
    AdjMatrix matrix;
    matrix.push_back(vector<int>());
    matrix.push_back(vector<int>());
    matrix.push_back(vector<int>());
    matrix[0].push_back(0); matrix[0].push_back(1); matrix[0].push_back(0);
    matrix[1].push_back(0); matrix[1].push_back(0); matrix[1].push_back(1);
    matrix[2].push_back(1); matrix[2].push_back(0); matrix[2].push_back(0);

    AdjList list = matrixToList(matrix);
    EdgeList edges = matrixToEdges(matrix);

    printMatrix(matrix);
    printList(list);
    printEdges(edges);

    return 0;
}

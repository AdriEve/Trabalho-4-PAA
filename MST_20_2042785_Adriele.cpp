#include <iostream>
#include <vector>
#include <algorithm>

struct Aresta {
    int u, v;
    long long peso;

    bool operator<(const Aresta& outra) const {
        return peso < outra.peso;
    }
};

struct DSU {
    std::vector<int> pai;

    DSU(int n) {
        pai.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            pai[i] = i;
        }
    }

    int encontrar(int i) {
        if (pai[i] == i)
            return i;
        return pai[i] = encontrar(pai[i]);
    }

    bool unir(int i, int j) {
        int raiz_i = encontrar(i);
        int raiz_j = encontrar(j);

        if (raiz_i != raiz_j) {
            pai[raiz_i] = raiz_j;
            return true;
        }
        return false;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    if (!(std::cin >> n >> m)) return 0;

    std::vector<Aresta> arestas(m);
    for (int i = 0; i < m; i++) {
        std::cin >> arestas[i].u >> arestas[i].v >> arestas[i].peso;
    }

    std::sort(arestas.begin(), arestas.end());

    DSU dsu(n);
    long long peso_total_mst = 0;
    int arestas_incluidas = 0;

    for (int i = 0; i < m; i++) {
        if (dsu.unir(arestas[i].u, arestas[i].v)) {
            peso_total_mst += arestas[i].peso;
            arestas_incluidas++;

            if (arestas_incluidas == n - 1) {
                break;
            }
        }
    }

    std::cout << peso_total_mst << "\n";

    return 0;
}
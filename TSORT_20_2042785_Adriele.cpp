#include <iostream>
#include <vector>

void trocar(int &a, int &b) {
    int temporario = a;
    a = b;
    b = temporario;
}

int particionar(std::vector<int> &vetor, int baixo, int alto) {
    int pivo = vetor[baixo + (alto - baixo) / 2];
    int i = baixo - 1;
    int j = alto + 1;

    while (true) {
        do {
            i++;
        } while (vetor[i] < pivo);

        do {
            j--;
        } while (vetor[j] > pivo);

        if (i >= j) {
            return j;
        }

        trocar(vetor[i], vetor[j]);
    }
}

void quicksort(std::vector<int> &vetor, int baixo, int alto) {
    if (baixo < alto) {
        int p = particionar(vetor, baixo, alto);

        quicksort(vetor, baixo, p);
        quicksort(vetor, p + 1, alto);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    if (!(std::cin >> t)) return 0;

    std::vector<int> vetor(t);

    for (int i = 0; i < t; i++) {
        std::cin >> vetor[i];
    }

    if (t > 0) {
        quicksort(vetor, 0, t - 1);
    }

    for (int i = 0; i < t; i++) {
        std::cout << vetor[i] << "\n";
    }

    return 0;
}
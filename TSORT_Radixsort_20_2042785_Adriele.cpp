#include <iostream>
#include <vector>

const int MAX_VAL = 1000000;

void countingSort(const std::vector<int> &vetor_entrada, std::vector<int> &vetor_saida) {
    std::vector<int> contagem(MAX_VAL + 1, 0);

    for (int num : vetor_entrada) {
        contagem[num]++;
    }

    for (int i = 1; i <= MAX_VAL; i++) {
        contagem[i] += contagem[i - 1];
    }

    for (int i = vetor_entrada.size() - 1; i >= 0; i--) {
        int num = vetor_entrada[i];
        vetor_saida[contagem[num] - 1] = num;
        contagem[num]--;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    if (!(std::cin >> t)) return 0;

    std::vector<int> vetor_entrada(t);
    std::vector<int> vetor_saida(t);

    for (int i = 0; i < t; i++) {
        std::cin >> vetor_entrada[i];
    }

    if (t > 0) {
        countingSort(vetor_entrada, vetor_saida);
    }

    for (int i = 0; i < t; i++) {
        std::cout << vetor_saida[i] << "\n";
    }

    return 0;
}
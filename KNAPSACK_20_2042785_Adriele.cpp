#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int S, N;
    if (!(std::cin >> S >> N)) return 0;

    std::vector<int> dp(S + 1, 0);

    for (int i = 0; i < N; i++) {
        int peso, valor;
        std::cin >> peso >> valor;

        for (int w = S; w >= peso; w--) {
            dp[w] = std::max(dp[w], dp[w - peso] + valor);
        }
    }

    std::cout << dp[S] << "\n";

    return 0;
}
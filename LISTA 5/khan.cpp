
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Algoritmo de Kahn
void kahn(int n, vector<vector<int>>& grafo) {

    // Armazena o grau de entrada de cada vertice
    vector<int> grauEntrada(n, 0);

    // Calcula o grau de entrada
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < (int)grafo[i].size(); j++) {

            int vizinho = grafo[i][j];

            grauEntrada[vizinho]++;
        }
    }

    // Fila dos vertices com grau de entrada zero
    queue<int> fila;

    for (int i = 0; i < n; i++) {

        if (grauEntrada[i] == 0) {
            fila.push(i);
        }
    }

    // Guarda a ordenacao topologica
    vector<int> ordem;

    // Processa os vertices
    while (!fila.empty()) {

        // Retira o primeiro vertice da fila
        int atual = fila.front();
        fila.pop();

        // Adiciona na ordenacao
        ordem.push_back(atual);

        // Percorre os vizinhos do vertice atual
        for (int i = 0; i < (int)grafo[atual].size(); i++) {

            int vizinho = grafo[atual][i];

            // Remove a dependencia do vizinho
            grauEntrada[vizinho]--;

            // Se nao possui mais dependencias
            if (grauEntrada[vizinho] == 0) {

                fila.push(vizinho);
            }
        }
    }

    // Verifica se todos os vertices foram processados
    if ((int)ordem.size() != n) {

        cout << "O grafo possui ciclo. "
             << "Nao existe ordenacao topologica." << endl;

        return;
    }

    // Exibe a ordenacao topologica
    cout << "\nOrdenacao topologica:\n";

    for (int i = 0; i < (int)ordem.size(); i++) {

        cout << ordem[i] << " ";
    }

    cout << endl;
}

int main() {

    int n, m;

    cout << "Quantidade de vertices e arestas: ";
    cin >> n >> m;

    // Cria a lista de adjacencia
    vector<vector<int>> grafo(n);

    cout << "Digite as arestas (origem destino):\n";

    for (int i = 0; i < m; i++) {

        int u, v;

        cin >> u >> v;

        // Grafo direcionado: u aponta para v
        grafo[u].push_back(v);
    }

    // Executa Kahn
    kahn(n, grafo);

    return 0;
}

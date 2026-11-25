
#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

// Estrutura para guardar uma aresta da MST
struct Aresta {
    int origem;
    int destino;
    int peso;

    Aresta(int o, int d, int p) {
        origem = o;
        destino = d;
        peso = p;
    }
};

// Algoritmo de Prim
void prim(int n, vector<vector<pair<int, int>>>& grafo) {

    // Controla os vertices que ja foram visitados
    vector<bool> visitado(n, false);

    // Fila de prioridade: menor peso primeiro
    // Guarda: peso, origem e destino
    typedef pair<int, pair<int, int>> Estado;

    priority_queue<Estado, vector<Estado>, greater<Estado>> fila;

    // Guarda as arestas selecionadas
    vector<Aresta> mst;

    int custoTotal = 0;

    // Comeca pelo vertice 0
    fila.push(make_pair(0, make_pair(0, 0)));

    while (!fila.empty()) {

        // Pega a aresta de menor peso
        Estado atual = fila.top();
        fila.pop();

        int peso = atual.first;
        int origem = atual.second.first;
        int destino = atual.second.second;

        // Ignora vertices que ja foram visitados
        if (visitado[destino]) {
            continue;
        }

        // Marca o vertice como visitado
        visitado[destino] = true;

        // Adiciona a aresta na MST
        // Exceto a inicializacao ficticia
        if (origem != destino) {

            mst.push_back(Aresta(origem, destino, peso));

            custoTotal += peso;
        }

        // Percorre os vizinhos do vertice atual
        for (int i = 0; i < (int)grafo[destino].size(); i++) {

            int vizinho = grafo[destino][i].first;
            int pesoAresta = grafo[destino][i].second;

            // Verifica se o vizinho ainda nao foi visitado
            if (!visitado[vizinho]) {

                fila.push(
                    make_pair(pesoAresta, make_pair(destino, vizinho))
                );
            }
        }
    }

    // Verifica se todos os vertices foram conectados
    if ((int)mst.size() != n - 1) {

        cout << "O grafo nao e conexo. Nao existe MST completa." << endl;

        return;
    }

    // Exibe as arestas da MST
    cout << "\nArestas da Arvore Geradora Minima:\n";

    for (int i = 0; i < (int)mst.size(); i++) {

        cout << mst[i].origem << " - " << mst[i].destino
             << " | Peso: " << mst[i].peso << endl;
    }

    cout << "\nCusto total da MST: " << custoTotal << endl;
}

int main() {

    int n, m;

    cout << "Quantidade de vertices e arestas: ";
    cin >> n >> m;

    // Cria a lista de adjacencia
    vector<vector<pair<int, int>>> grafo(n);

    cout << "Digite as arestas (origem destino peso):\n";

    for (int i = 0; i < m; i++) {

        int u, v, peso;

        cin >> u >> v >> peso;

        // Adiciona a aresta nos dois sentidos
        grafo[u].push_back(make_pair(v, peso));
        grafo[v].push_back(make_pair(u, peso));
    }

    // Executa o algoritmo de Prim
    prim(n, grafo);

    return 0;
}

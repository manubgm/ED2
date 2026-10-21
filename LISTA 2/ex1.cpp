#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

// Classe que representa o Grafo Direcionado Não Ponderado
class Grafo {
private:
    int numVertices;
    vector<vector<int>> adj; // Lista de adjacência

    // Função auxiliar recursiva para a DFS
    void dfsRec(int u, vector<bool>& visitado, vector<int>& pai) {
        visitado[u] = true;

        for (int v : adj[u]) {
            if (!visitado[v]) {
                pai[v] = u; // Registra o pai para reconstruir o caminho
                dfsRec(v, visitado, pai);
            }
        }
    }

    // Função auxiliar para reconstruir e imprimir o caminho
    void imprimirCaminho(int inicio, int destino, const vector<int>& pai) {
        if (destino == inicio) {
            cout << inicio;
            return;
        }

        vector<int> caminho;
        for (int v = destino; v != -1; v = pai[v]) {
            caminho.push_back(v);
        }

        reverse(caminho.begin(), caminho.end());

        for (size_t i = 0; i < caminho.size(); ++i) {
            cout << caminho[i];
            if (i < caminho.size() - 1) cout << " -> ";
        }
    }

public:
    Grafo(int v) : numVertices(v), adj(v) {}

    // a. Inserir aresta (u -> v)
    void adicionarAresta(int u, int v) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            adj[u].push_back(v);
            cout << "Aresta (" << u << " -> " << v << ") inserida com sucesso.\n";
        } else {
            cout << "Vértices inválidos!\n";
        }
    }

    // b. Busca em Profundidade (DFS)
    void executarDFS(int inicio) {
        if (inicio < 0 || inicio >= numVertices) {
            cout << "Vértice de início inválido!\n";
            return;
        }

        vector<bool> visitado(numVertices, false);
        vector<int> pai(numVertices, -1);

        dfsRec(inicio, visitado, pai);

        cout << "\n--- Resultados da DFS a partir do vértice " << inicio << " ---\n";
        bool algumAlcancavel = false;

        for (int i = 0; i < numVertices; ++i) {
            if (visitado[i] && i != inicio) {
                algumAlcancavel = true;
                cout << "Vértice alcançável: " << i << " | Caminho: ";
                imprimirCaminho(inicio, i, pai);
                cout << "\n";
            }
        }

        if (!algumAlcancavel) {
            cout << "Nenhum outro vértice é alcançável a partir de " << inicio << ".\n";
        }
    }

    // c. Busca em Largura (BFS)
    void executarBFS(int inicio) {
        if (inicio < 0 || inicio >= numVertices) {
            cout << "Vértice de início inválido!\n";
            return;
        }

        vector<bool> visitado(numVertices, false);
        vector<int> pai(numVertices, -1);
        queue<int> fila;

        visitado[inicio] = true;
        fila.push(inicio);

        while (!fila.empty()) {
            int u = fila.front();
            fila.pop();

            for (int v : adj[u]) {
                if (!visitado[v]) {
                    visitado[v] = true;
                    pai[v] = u;
                    fila.push(v);
                }
            }
        }

        cout << "\n--- Resultados da BFS a partir do vértice " << inicio << " ---\n";
        bool algumAlcancavel = false;

        for (int i = 0; i < numVertices; ++i) {
            if (visitado[i] && i != inicio) {
                algumAlcancavel = true;
                cout << "Vértice alcançável: " << i << " | Caminho mais curto: ";
                imprimirCaminho(inicio, i, pai);
                cout << "\n";
            }
        }

        if (!algumAlcancavel) {
            cout << "Nenhum outro vértice é alcançável a partir de " << inicio << ".\n";
        }
    }
};

int main() {
    int v;
    cout << "Digite o numero de vertices do grafo: ";
    cin >> v;

    Grafo g(v);
    int opcao;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Inserir aresta\n";
        cout << "2. Aplicar DFS\n";
        cout << "3. Aplicar BFS\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        if (opcao == 1) {
            int u, dest;
            cout << "Digite o vertice de origem (0 a " << v - 1 << "): ";
            cin >> u;
            cout << "Digite o vertice de destino (0 a " << v - 1 << "): ";
            cin >> dest;
            g.adicionarAresta(u, dest);
        } 
        else if (opcao == 2) {
            int origem;
            cout << "Digite o vertice de origem para DFS: ";
            cin >> origem;
            g.executarDFS(origem);
        } 
        else if (opcao == 3) {
            int origem;
            cout << "Digite o vertice de origem para BFS: ";
            cin >> origem;
            g.executarBFS(origem);
        }
    } while (opcao != 0);

    return 0;
}
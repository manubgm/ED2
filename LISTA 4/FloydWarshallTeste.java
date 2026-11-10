import java.util.*;

public class FloydWarshallTeste {
    static final long INF = Long.MAX_VALUE / 4;

    static long[][] floydWarshall(int n, int[][] arestas) {
        long[][] dist = new long[n][n];

        for (int i = 0; i < n; i++) {
            Arrays.fill(dist[i], INF);
            dist[i][i] = 0;
        }

        for (int[] e : arestas) {
            int u = e[0], v = e[1], peso = e[2];
            dist[u][v] = Math.min(dist[u][v], peso);
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                if (dist[i][k] == INF) continue;

                for (int j = 0; j < n; j++) {
                    if (dist[k][j] == INF) continue;

                    long candidato = dist[i][k] + dist[k][j];
                    if (candidato < dist[i][j]) {
                        dist[i][j] = candidato;
                    }
                }
            }
        }
        return dist;
    }

    static void mostrar(String[] nomes, long[][] dist) {
        System.out.print("    ");
        for (String nome : nomes) System.out.printf("%5s", nome);
        System.out.println();

        for (int i = 0; i < nomes.length; i++) {
            System.out.printf("%-4s", nomes[i]);
            for (int j = 0; j < nomes.length; j++) {
                if (dist[i][j] == INF) System.out.printf("%5s", "INF");
                else System.out.printf("%5d", dist[i][j]);
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        String[] nomes1 = {"A", "B", "C", "D", "E", "F"};
        int[][] g1 = {
            {0, 1, 1}, {0, 2, 3}, {1, 2, 1},
            {1, 3, 2}, {1, 4, 3}, {2, 4, 2},
            {3, 5, 3}, {4, 3, -3}, {4, 5, 2}
        };

        System.out.println("Matriz final do grafo A-F:");
        mostrar(nomes1, floydWarshall(6, g1));

        String[] nomes2 = {"S", "A", "B", "C", "D", "T"};
        int[][] g2 = {
            {0, 1, 5}, {0, 3, -2}, {3, 1, 2},
            {1, 2, 1}, {3, 2, 4}, {2, 4, -1},
            {2, 5, 3}, {3, 4, 4}, {4, 5, 1}
        };

        System.out.println("\nMatriz final do grafo S-T:");
        mostrar(nomes2, floydWarshall(6, g2));
    }
}

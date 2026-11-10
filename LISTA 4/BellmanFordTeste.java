import java.util.*;

public class BellmanFordTeste {
    static final long INF = Long.MAX_VALUE / 4;

    static class Aresta {
        int origem, destino;
        long peso;

        Aresta(int origem, int destino, long peso) {
            this.origem = origem;
            this.destino = destino;
            this.peso = peso;
        }
    }

    static long[] bellmanFord(int n, List<Aresta> arestas, int origem) {
        long[] dist = new long[n];
        Arrays.fill(dist, INF);
        dist[origem] = 0;

        for (int i = 1; i < n; i++) {
            boolean mudou = false;

            for (Aresta e : arestas) {
                if (dist[e.origem] != INF &&
                    dist[e.origem] + e.peso < dist[e.destino]) {
                    dist[e.destino] = dist[e.origem] + e.peso;
                    mudou = true;
                }
            }

            if (!mudou) break;
        }

        for (Aresta e : arestas) {
            if (dist[e.origem] != INF &&
                dist[e.origem] + e.peso < dist[e.destino]) {
                throw new IllegalStateException(
                    "Existe ciclo negativo alcancavel pela origem.");
            }
        }
        return dist;
    }

    static void mostrar(String[] nomes, long[] dist) {
        for (int i = 0; i < nomes.length; i++) {
            System.out.println(nomes[i] + ": " +
                (dist[i] == INF ? "INF" : dist[i]));
        }
    }

    public static void main(String[] args) {
        String[] nomes1 = {"A", "B", "C", "D", "E", "F"};
        List<Aresta> g1 = new ArrayList<>();
        g1.add(new Aresta(0, 1, 1));   // A -> B
        g1.add(new Aresta(0, 2, 3));   // A -> C
        g1.add(new Aresta(1, 2, 1));   // B -> C
        g1.add(new Aresta(1, 3, 2));   // B -> D
        g1.add(new Aresta(1, 4, 3));   // B -> E
        g1.add(new Aresta(2, 4, 2));   // C -> E
        g1.add(new Aresta(3, 5, 3));   // D -> F
        g1.add(new Aresta(4, 3, -3));  // E -> D
        g1.add(new Aresta(4, 5, 2));   // E -> F

        System.out.println("Grafo A-F, origem A:");
        mostrar(nomes1, bellmanFord(6, g1, 0));

        // Grafo do exercício dos slides: S, A, B, C, D, T
        String[] nomes2 = {"S", "A", "B", "C", "D", "T"};
        List<Aresta> g2 = new ArrayList<>();
        g2.add(new Aresta(0, 1, 5));   // S -> A
        g2.add(new Aresta(0, 3, -2));  // S -> C
        g2.add(new Aresta(3, 1, 2));   // C -> A
        g2.add(new Aresta(1, 2, 1));   // A -> B
        g2.add(new Aresta(3, 2, 4));   // C -> B
        g2.add(new Aresta(2, 4, -1));  // B -> D
        g2.add(new Aresta(2, 5, 3));   // B -> T
        g2.add(new Aresta(3, 4, 4));   // C -> D
        g2.add(new Aresta(4, 5, 1));   // D -> T

        System.out.println("\nGrafo S-T, origem S:");
        mostrar(nomes2, bellmanFord(6, g2, 0));
    }
}

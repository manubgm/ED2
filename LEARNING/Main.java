public class Main {
    public static void main(String[] args){
        Grafo grafo = new Grafo();

        grafo.adicionarVertice("A");
        grafo.adicionarVertice("B");
        grafo.adicionarVertice("C");

        grafo.adicionarAresta("A","B");
        grafo.adicionarAresta("A","C");
        grafo.adicionarAresta("B","C");

        grafo.exibirGrafo();

        
    }
}

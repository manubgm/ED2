
import java.util.ArrayList;
import java.util.List;

public class Grafo {
    
    private List<String> vertices;

    private List<List<String>> adjacencias;
    //em c++ usariamos vector vector<vector<string> adjacencias;

    /* versao 1 
    public Grafo(int quantidadeVertices){
        adjacencias = new ArrayList<>();
        

        for(int i=0;i<quantidadeVertices;i++){
            adjacencias.add(new ArrayList<>());
        }
        //pra cada vertice do numero de arestas crio uma lista vazia de vizinhos
    }*/

    public Grafo(){
        adjacencias = new ArrayList<>();
        vertices = new ArrayList<>();
    }

    public void adicionarVertice(String nome){
        vertices.add(nome);
        adjacencias.add(new ArrayList<>());
    }

    public int buscarIndice(String nome){
        return vertices.indexOf(nome);
    }

    public void adicionarAresta(String origem, String destino){
        int indOrigem = buscarIndice(origem);
        int indDestino = buscarIndice(destino);

        if(indOrigem == -1|| indDestino == -1){//basta um dos vertices nao existirem pra dar erro
            System.out.println("Erro: vértice não encontrado (ou os indices de origem e destino estão errados");
            return;
        }

        //conexão
        adjacencias.get(indOrigem).add(destino);
        //coloca o vertice(string) do destino na lista do indice da origem
        //acessamos a lista de vizinhos da origem e adicionamos o destino.
        //Como o grafo é direcionado,
        //  adicionar A → B não cria automaticamente B → A
    }

    public void exibirGrafo(){
        for(int i=0;i<vertices.size();i++){
            System.out.println(vertices.get(i)+"->"+adjacencias.get(i));
        }
    }

}



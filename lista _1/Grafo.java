import java.util.ArrayList;
import java.util.List;

public class Grafo{
   
    static class Aresta{
        int destino;
        int peso;

        public Aresta(int destino,int peso){
            this.destino=destino;
            this.peso=peso;
        }
    }

    int numVertices;

    List<List<Aresta>> adjacencia;

    boolean ehorientado;

    public Grafo(int numVertices,boolean ehorientado){
        this.ehorientado=ehorientado;
        this.numVertices=numVertices;

        adjacencia = new ArrayList<>();

        for(int i=0;i<numVertices;i++){
            adjacencia.add(new ArrayList<>());
        }
    }

    public static void main(String[] args){
    }
}
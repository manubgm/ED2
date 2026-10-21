
import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        //leitura
        int f = sc.nextInt();
        int s = sc.nextInt();
        int g = sc.nextInt();
        int u = sc.nextInt();
        int d = sc.nextInt();

        Queue<Integer> fila = new LinkedList<>();
        int[] distancia = new int[f + 1];
        Arrays.fill(distancia,-1);

        //coloca o inicial na fila
        fila.add(s);
        distancia[s] = 0;//s ja visitado

        while(!fila.isEmpty()){

            //retira o primeiro da fila
            int atual = fila.poll();

            int cima= atual+u;
            int baixo = atual-d;

            if(cima>=1 &&cima <=f && distancia[cima]==-1){
               distancia[cima]=distancia[atual]+1;
               fila.add(cima);
            }
            if(baixo>=1 && baixo<=f && distancia[baixo]==-1){
                distancia[baixo]=distancia[atual]+1;
                fila.add(baixo);
            }
        }

        if(distancia[g]==-1){
            System.out.println("use the stairs");
        }else{
            System.out.println(distancia[g]);
        }

    }
}

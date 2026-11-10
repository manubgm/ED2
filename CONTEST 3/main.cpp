#include <bits/stdc++.h>
using namespace std;

struct Aresta{
    int origem;
    int destino;
    int peso;
};

int main(){
    //leitura
    int n,m;
    cin>>n>>m;
    vector<Aresta> arestas;
    for(int i=0;i<m; i++){
        Aresta a;
        cin>>a.origem>>a.destino>>a.peso;
        arestas.push_back(a);
    
    }

    //logica
    vector<int> distancia(n+1,INT_MAX);
    /*inicia com um valor absurdamente grnde pq ai toda distancia vai ser menor q ele*/
    distancia[1]= 0;


    for(int i=0;i<n-1;i++){     //passagens
        for(int j=0;j<m;j++){   //arestas
            Aresta a = arestas[j];

            if(distancia[a.origem]!=INT_MAX && distancia[a.destino]>distancia[a.origem]+a.peso){
            distancia[a.destino]=distancia[a.origem]+a.peso;
            }
        }
    }

    //saida
    for(int i=1;i<=n;i++){
        if(distancia[i]==INT_MAX){
            cout<<30000;
        }else{
            cout<< distancia[i];
        }
        cout<<" ";
    }
    return 0;
}
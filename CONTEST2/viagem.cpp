#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    int n,m;

    while(cin>>n>>m){

        vector<vector<pair<int,int>>> onibus(n+1);
        vector<vector<pair<int,int>>> aviao(n+1);

        for(int i=0;i<m;i++){
            int a,b,t,r;

            cin>>a>>b>>t>>r;

            //coloca eles em cada lisa com um if
            if(t==0){
                //vector do onibus
                onibus[a].push_back({b,r});
            }
            if(t==1){
                //vector do aviao
                aviao[a].push_back({b,r});
            }
        }

        vector<int> distancia(n+1,INT_MAX);
        distancia[1]=0;
        vector<int> distanciaAviao(n + 1, INT_MAX);
        distanciaAviao[1]=0;

        priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
        > filaO;

        priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
        > filaA;

        filaO.push({0,1});//custo zero pra cidade 1
        filaA.push({0,1});

        while(!filaO.empty()){
            pair<int,int> atual = filaO.top();//ve o par com menor custo
            filaO.pop();//tira ele 
            
            
            int custoAtual = atual.first;
            int cidadeAtual = atual.second;
            
            if (custoAtual > distancia[cidadeAtual]) {
                continue;
            }


            for(auto aresta : onibus[cidadeAtual]){
                int vizinho = aresta.first;
                int custoAresta = aresta.second;

                int novoCusto = custoAtual + custoAresta;
                if(novoCusto<distancia[vizinho]){
                    distancia[vizinho]= novoCusto;
                    filaO.push({novoCusto, vizinho});
                }
            }

           
        }

        while(!filaA.empty()){
            pair<int,int> atual = filaA.top();//ve o par com menor custo
            filaA.pop();//tira ele 


            int custoAtual = atual.first;
            int cidadeAtual = atual.second;

            if (custoAtual > distanciaAviao[cidadeAtual]) {
                continue;
            }

            for(auto aresta : aviao[cidadeAtual]){
                int vizinho = aresta.first;
                int custoAresta = aresta.second;

                int novoCusto = custoAtual + custoAresta;
                if(novoCusto<distanciaAviao[vizinho]){
                    distanciaAviao[vizinho]= novoCusto;
                    filaA.push({novoCusto, vizinho});
                }
            }

        }


        cout << min(distancia[n], distanciaAviao[n]) << '\n';

    }


    return 0;
}
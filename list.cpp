#include<iostream>

using namespace std;

class No{

    private:
        No* proximo = NULL;
        No* anterior = NULL;
        int valor; 

    public:
        No(int v){
            valor = v;
        }   

        int NoValor(){
            return valor;
        }

        No* NoProximo(){
            return proximo;
        }

        No* NoAnterior(){
            return anterior;
        }

        void AlteraProximo(No* NovoProximo){
            proximo = NovoProximo;
        }

        void AlteraAnterior(No* NovoAnterior){
            anterior = NovoAnterior;
        }        
};


class Lista{ 

    private:
        No* primeiro;
        No* ultimo;
        int quantidade = 0;        

    public:
        int push(int valor, int pos){

            if (pos > quantidade+1){
                throw "posição não disponível";
            }

            No* novo = new No(valor); 

             if (quantidade == 0){
                primeiro = novo;  
                ultimo = novo;                   
            }

            else{
              int i = 0; 
              No* aux1 = primeiro;
              No* aux2 = primeiro;

              while(i < quantidade){
                  aux2 = aux1; 
                  aux1 = aux2->NoProximo();
                  i++;
              }

              novo->AlteraAnterior(aux2); 
              novo->AlteraProximo(aux1); 
              aux1->AlteraAnterior(novo);
              aux2->AlteraProximo(novo);
            }

            quantidade++;
        }


        bool pop(int pos){

            if(quantidade == 0){
                throw "Lista vazia";
            }    

            if(pos > quantidade){
                throw "Posição inexistente";
            }

            else{

                No* aux = primeiro; 
                int i = 0;

                while (i < pos){
                    aux = aux->NoProximo();
                }

                aux->NoProximo()->AlteraAnterior(aux->NoAnterior());
                aux->NoAnterior()->AlteraProximo(aux->NoProximo());
                delete(aux);
                quantidade--;
            }
        }


        int consultar(){
            return quantidade;
        }


        bool imprimir(){

            if (quantidade == 0){
                cout << "Lista Vazia!" << endl;
                return false; 
            }

               
            int c = 0;
            No* aux = primeiro;

            while(c < quantidade){
                cout << aux->NoValor() << "\t";
                aux = aux->NoProximo();
                c++;
            }
            cout << endl;
        }
};


int main(){

    Lista* l1 = new Lista;

    int i = 1; 
    int j = 0; 

    while(i <= 10){
        l1->push(i, j);
        j++;
        i++;
    }

    cout << "Quantidade: " << l1->consultar() << endl;
  
    while(i > 1){
        l1->imprimir();
        l1->pop(4);
        i--;
    }    

    cout << "Quantidade: " << l1->consultar() << endl;

    return 0;
}
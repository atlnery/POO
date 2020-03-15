#include<iostream>

//fila - FIFO

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


class Fila{ 

    private:
        No* primeiro;
        No* ultimo;
        int quantidade = 0;        

    public:
        int push(int valor){
            
            No* novo = new No(valor); 
            
            if (quantidade == 0){
                primeiro = novo;                     
            }

            else{
               ultimo->AlteraProximo(novo);
            }

            novo->AlteraAnterior(ultimo);
            ultimo = novo;
            quantidade++;
        }


        bool pop(){

            if(quantidade == 0){
                cout << "Lista Vazia" << endl;
                return false;
            }    

            else{
                primeiro = primeiro->NoProximo();
                delete(primeiro->NoAnterior());
                primeiro->AlteraAnterior(NULL);
                quantidade--;
                return false; 
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

    Fila* f1 = new Fila;

    int i = 1; 

    while(i <= 10){
        f1->push(i);
        i++;
    }

    cout << "Quantidade: " << f1->consultar() << endl;
  
    while(i > 1){
        f1->imprimir();
        f1->pop();
        i--;
    }    

    cout << "Quantidade: " << f1->consultar() << endl;

    return 0;
}
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


class Pilha{ 

    private:
        No* primeiro;
        No* ultimo;
        int quantidade = 0;        

    public:
        void push(int valor){

            No* novo = new No(valor); 

            if (quantidade == 0){
                primeiro = novo;  
            }
    
           else{
              novo->AlteraProximo(ultimo);
              ultimo->AlteraAnterior(novo);
            }

            ultimo = novo;
            quantidade++;
        }


        bool pop(){ //posição que quer remover

            if(quantidade == 0){
                throw "Pilha vazia";
            }    

            else{
                No* aux = ultimo; 

                ultimo = aux->NoProximo();
                ultimo->AlteraAnterior(NULL);   
                delete aux;                        
            }
            quantidade--;
        }


        int consultar(){
            return quantidade;
        }


        bool imprimir(){

            if (quantidade == 0){
                cout << "Pilha Vazia!" << endl;
                return false; 
            }

            cout << endl;
            
            int c = 0;
            No* aux = ultimo;

            while(c < quantidade){
                cout << aux->NoValor() << "\n";
                aux = aux->NoProximo();
                c++;
            }
            cout << endl;
        }
};


int main(){

    Pilha* p1 = new Pilha;

    int i = 1; 
    int j = 0; 

    while(i <= 10){
        p1->push(i);
        i++;
    }

    
    p1->imprimir();
    
    cout << "Quantidade: " << p1->consultar() << endl;

    p1->pop();
    p1->pop();
    p1->pop();

    p1->imprimir();

    cout << "Quantidade: " << p1->consultar() << endl;

}
#include <iostream>
using namespace std;
 
struct nodo{
    int numero;
    struct nodo *siguiente, *ptrPila;
};

typedef nodo *ptrPila; 

void push( ptrPila &pila, int valor )
{
     ptrPila aux;
     aux = new(struct nodo);  
     aux->numero = valor;
     
     aux->siguiente = pila ;
     pila = aux ;
}
 

int pop( ptrPila &pila )
{
     int num ;
     ptrPila aux;
     
     aux = pila ;
     num = aux->numero;   
     
     pila = aux->siguiente ;
     delete(aux);
     
     return num;
}
 
void mostrarPila( ptrPila pila )
{
     ptrPila aux;
     aux = pila;    
     
     while( aux !=NULL )
     {
            cout<<"\t"<< aux->numero <<endl;
            aux = aux->siguiente;
     }    
}
 

void destruir_pila( ptrPila &pila)
{
     ptrPila aux;
     
     while( pila != NULL)
     {
           aux = pila;
           pila = aux->siguiente;
           delete(aux);
     }
}
 

void menu()
{
    cout<<"\n\t MENU \n\n";
    cout<<" 1. APILAR"<<endl;
    cout<<" 2. DESAPILAR"<<endl;
    cout<<" 3. MOSTRAR PILA"<<endl;
    cout<<" 4. DESTRUIR PILA "<<endl;
    cout<<" 5. SALIR"<<endl;
 
    cout<<"\n INGRESE OPCION: ";
}
 

int main()
{
    ptrPila pila = NULL;  
    int dato;
    int op;
    int x ; 
 
    do
    {
        menu();  cin>> op;
 
        switch(op)
        {
            case 1:
 
                 cout<< "\n NUMERO A APILAR: "; cin>> dato;
                 push( pila, dato );
                 cout<<"\n\n\t\tNumero " << dato << " apilado...\n\n";
            break;
 
 
            case 2:
 
                 x = pop( pila );
                 cout<<"\n\n\t\tNumero "<< x <<" desapilado...\n\n";
            break;
                 
 
            case 3:
 
                 cout << "\n\n MOSTRANDO PILA\n\n";
                 if(pila!=NULL)
                    mostrarPila( pila );
                 else
                    cout<<"\n\n\tPila vacia..!"<<endl;
            break;
 
 
            case 4:
 
                 destruir_pila( pila );
                 cout<<"\n\n\t\tPila eliminada...\n\n";
            break;
           
         }
 
        cout<<endl<<endl;
        system("pause");  system("cls");
 
    }while(op!=5);
   
   
    return 0;
}

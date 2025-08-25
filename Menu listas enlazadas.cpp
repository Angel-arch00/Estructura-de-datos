#include <iostream>
#include<stdlib.h>
#include<string>
using namespace std;
 
struct listaNodo{
   int dato;
   struct listaNodo *next;
};
 
typedef struct listaNodo LISTANODO; 
typedef LISTANODO *apuntador_LISTANODO;
 
void insertar(apuntador_LISTANODO *,int); 
void imprimir(apuntador_LISTANODO);
int eliminar(apuntador_LISTANODO *, int);
int buscar(apuntador_LISTANODO *, int);

void insertar(apuntador_LISTANODO *inicio, int valor)
{
    apuntador_LISTANODO nuevo,previo,actual;
    nuevo=new LISTANODO();
    if(nuevo!=NULL){
        nuevo->dato=valor;
        nuevo->next=NULL;
        previo=NULL;
        actual=*inicio;
        while(actual!=NULL && valor>actual->dato){
            previo=actual;
            actual=actual->next;
        }
        if(previo==NULL){
            nuevo->next=*inicio;
            *inicio=nuevo;
        }
        else{
            previo->next=nuevo;
            nuevo->next=actual;
        }
    }else{
        cout<<valor<<" No insertado"<<endl;
    }
}

void imprimir (apuntador_LISTANODO actual){
    if(actual==NULL){
        cout<<"La lista está vacia"<<endl;
    }else{
        while(actual!=NULL){
            cout<<"->"<<actual->dato<<endl;
            actual=actual->next;
        }
        cout<<"NULL"<<endl;
    }
}

int eliminar (apuntador_LISTANODO *inicio, int valor){
    apuntador_LISTANODO previo, actual, temporal;
    if (*inicio!=NULL && valor==(*inicio)->dato){
        temporal= *inicio;
        *inicio=(*inicio)->next;
        delete temporal;
        cout<<"Eliminado correctamente"<<endl;
        return valor;
    } 
    else {
        previo= *inicio;
        if(previo==NULL){
            cout<<"La lista está vacía"<<endl;
            return 0;
        } 
        actual=(*inicio)->next;
        while(actual!=NULL && actual->dato!=valor){
            previo=actual;
            actual=actual->next;
        }
        if(actual!=NULL){
            temporal=actual;
            previo->next=actual->next;
            delete temporal;
            cout<<"Eliminado correctamente"<<endl;
            return valor;
        }
        else{
            cout<<"No se encontró"<<endl;
        }
    }
    return 0;
}

int buscar (apuntador_LISTANODO *inicio, int valor){
    apuntador_LISTANODO actual = *inicio;
    while(actual!=NULL && actual->dato!=valor){
        actual=actual->next;
    }
    if(actual!=NULL){
        cout<<"El dato se encontró: "<<valor<<endl;
        return valor;
    }
    else{
        cout<<"El dato no se encontró"<<endl;
    }
    return 0;
}

int main(){
    apuntador_LISTANODO lista=NULL;
    int opcion, valor;

    do {
        cout<<"\n--- MENU LISTA ENLAZADA ---"<<endl;
        cout<<"1. Insertar nodo"<<endl;
        cout<<"2. Eliminar nodo"<<endl;
        cout<<"3. Buscar nodo"<<endl;
        cout<<"4. Imprimir lista"<<endl;
        cout<<"5. Salir"<<endl;
        cout<<"Seleccione una opcion: ";
        cin>>opcion;

        switch(opcion){
            case 1:
                cout<<"Ingrese el valor a insertar: ";
                cin>>valor;
                insertar(&lista,valor);
                break;
            case 2:
                cout<<"Ingrese el valor a eliminar: ";
                cin>>valor;
                eliminar(&lista,valor);
                break;
            case 3:
                cout<<"Ingrese el valor a buscar: ";
                cin>>valor;
                buscar(&lista,valor);
                break;
            case 4:
                imprimir(lista);
                break;
            case 5:
                cout<<"Saliendo..."<<endl;
                break;
            default:
                cout<<"Opcion invalida"<<endl;
                break;
        }
    } while(opcion != 5);

    return 0;
}

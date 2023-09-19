#include <iostream>
using namespace std;

class Nodo
{
public:
    int info;
    Nodo* sig;
    Nodo* ant; // Nuevo puntero al nodo anterior
public:
    Nodo();
    Nodo(int dato);
};

Nodo::Nodo()
{
    info = 0;
    sig = NULL;
    ant = NULL;
}

Nodo::Nodo(int dato)
{
    info = dato;
    sig = NULL;
    ant = NULL;
}

class ListaDoblementeEnlazada
{
private:
    Nodo* cabeza; // Cambiamos el nombre de "raiz" a "cabeza" para mayor claridad
public:
    ListaDoblementeEnlazada();
    bool esVacia();
    void insertarInicio(int e);
    void insertarFinal(int e);
    int eliminarInicio();
    int eliminarFinal();
    void insertarPosicion(int e, int p);
    void mostrarLista();
};

ListaDoblementeEnlazada::ListaDoblementeEnlazada() { cabeza = NULL; }

bool ListaDoblementeEnlazada::esVacia()
{
    return (cabeza == NULL);
}

void ListaDoblementeEnlazada::insertarInicio(int dato)
{
    Nodo* nuevo = new Nodo(dato);

    if (esVacia())
    {
        cabeza = nuevo;
    }
    else
    {
        nuevo->sig = cabeza;
        cabeza->ant = nuevo; // Establecemos el enlace hacia el nodo anterior
        cabeza = nuevo;
    }
}

void ListaDoblementeEnlazada::mostrarLista()
{
    Nodo* aux = cabeza;

    if (!esVacia())
    {
        cout << "Cabeza" << " <--> ";
        while (aux != NULL)
        {
            cout << aux->info << " <--> ";
            aux = aux->sig;
        }
        cout << "NULL" << endl;
    }
    else
    {
        cout << "\nLa lista está vacía!\n";
    }
}

void ListaDoblementeEnlazada::insertarFinal(int dato)
{
    Nodo* nuevo = new Nodo(dato);

    if (esVacia())
    {
        cabeza = nuevo;
    }
    else
    {
        Nodo* aux = cabeza;

        while (aux->sig != NULL)
        {
            aux = aux->sig;
        }

        aux->sig = nuevo;
        nuevo->ant = aux; // Establecemos el enlace hacia el nodo anterior
    }
}

int ListaDoblementeEnlazada::eliminarInicio()
{
    int dato = INT_MAX;

    if (!esVacia())
    {
        Nodo* aux = cabeza;

        if (aux->sig == NULL)
        {
            cabeza = NULL;
        }
        else
        {
            cabeza = aux->sig;
            cabeza->ant = NULL; // Eliminamos el enlace hacia el nodo anterior
        }
        dato = aux->info;
        delete aux;
    }

    return dato;
}

int ListaDoblementeEnlazada::eliminarFinal()
{
    int dato = INT_MAX;

    if (!esVacia())
    {
        Nodo* anterior, * siguiente;
        siguiente = cabeza;
        anterior = siguiente;

        if (siguiente->sig == NULL)
        {
            cabeza = NULL;
        }
        else
        {
            while (siguiente->sig != NULL)
            {
                anterior = siguiente;
                siguiente = siguiente->sig;
            }

            anterior->sig = NULL;
        }

        dato = siguiente->info;
        delete siguiente;
    }

    return dato;
}

void ListaDoblementeEnlazada::insertarPosicion(int dato, int posicion)
{
    if (posicion < 0) // Si la posición es menor a cero no puede existir
    {
        cout << "Posición inválida." << endl;
        return;
    }

    Nodo* nuevo = new Nodo(dato);

    if (posicion == 0) // Si solo hay un elemento directamente lo inserta y recorre el elemento
    {
        nuevo->sig = cabeza;
        if (cabeza != NULL)
        {
            cabeza->ant = nuevo; // Establecemos el enlace hacia el nodo anterior
        }
        cabeza = nuevo;
        return;
    }

    Nodo* aux = cabeza;
    int contador = 0;

    while (contador < posicion - 1 && aux != NULL)
    {
        aux = aux->sig;
        contador++;
    }

    if (aux == NULL)
    {
        cout << "Posición fuera de rango." << endl;
        delete nuevo;
        return;
    }

    nuevo->sig = aux->sig;
    nuevo->ant = aux; // Establecemos el enlace hacia el nodo anterior
    if (aux->sig != NULL)
    {
        aux->sig->ant = nuevo; // Actualizamos el enlace del siguiente nodo al nuevo nodo
    }
    aux->sig = nuevo; // Actualizamos el enlace del nodo actual al nuevo nodo
}

// Imprimir al revés una LISTA DOLEMENTE ENLAZADA

void ListaDoblementeEnlazada::imprimirReversa()
{
    Nodo* aux = cabeza;

    if (!esVacia())
    {
        // Avanzamos hasta el último nodo de la lista
        while (aux->sig != NULL)
        {
            aux = aux->sig;
        }

        // Comenzamos desde el último nodo e imprimimos en reversa
        cout << "NULL" << " <--> ";
        while (aux != NULL)
        {
            cout << aux->info << " <--> ";
            aux = aux->ant;
        }
        cout << "Cabeza" << endl;
    }
    else
    {
        cout << "\nLa lista está vacía!\n";
    }
}



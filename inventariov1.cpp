#include <iostream>
#include <string>
using namespace std;

// estructura para los productos
struct Producto {
    int id;
    string nombre;
    float precio;
    int cantidad;
};

// funcion para mostrar un producto
void mostrarProducto(Producto *p) {
    cout << "ID: " << p->id << endl;
    cout << "Nombre: " << p->nombre << endl;
    cout << "Precio: $" << p->precio << endl;
    cout << "Cantidad: " << p->cantidad << endl;
    cout << "-------------------" << endl;
}

// funcion para mostrar todos los productos
void mostrarTodos(Producto inventario[], int total) {
    cout << "\n=== INVENTARIO COMPLETO ===" << endl;
    for(int i = 0; i < total; i++) {
        mostrarProducto(&inventario[i]);
    }
}

// funcion de busqueda por ID
void buscarPorID(Producto inventario[], int total, int idBuscar) {
    bool encontrado = false;
    try {
        for(int i = 0; i < total; i++) {
            if(inventario[i].id == idBuscar) {
                cout << "\nProducto encontrado:" << endl;
                mostrarProducto(&inventario[i]);
                encontrado = true;
                break;
            }
        }
        if(!encontrado) {
            throw idBuscar;
        }
    }
    catch(int id) {
        cout << "ERROR: No se encontro el producto con ID " << id << endl;
    }
}

// funcion de busqueda por nombre
void buscarPorNombre(Producto inventario[], int total, string nombreBuscar) {
    bool encontrado = false;
    try {
        for(int i = 0; i < total; i++) {
            if(inventario[i].nombre == nombreBuscar) {
                cout << "\nProducto encontrado:" << endl;
                mostrarProducto(&inventario[i]);
                encontrado = true;
            }
        }
        if(!encontrado) {
            throw nombreBuscar;
        }
    }
    catch(string nombre) {
        cout << "ERROR: No se encontro el producto " << nombre << endl;
    }
}

// ordenamiento burbuja por precio
void ordenarPorPrecio(Producto *inventario, int total) {
    Producto temp;
    for(int i = 0; i < total - 1; i++) {
        for(int j = 0; j < total - i - 1; j++) {
            if(inventario[j].precio > inventario[j + 1].precio) {
                temp = inventario[j];
                inventario[j] = inventario[j + 1];
                inventario[j + 1] = temp;
            }
        }
    }
    cout << "\nProductos ordenados por precio!" << endl;
}

// ordenamiento por cantidad usando seleccion
void ordenarPorCantidad(Producto *inventario, int total) {
    int minimo;
    Producto temp;
    for(int i = 0; i < total - 1; i++) {
        minimo = i;
        for(int j = i + 1; j < total; j++) {
            if(inventario[j].cantidad < inventario[minimo].cantidad) {
                minimo = j;
            }
        }
        if(minimo != i) {
            temp = inventario[i];
            inventario[i] = inventario[minimo];
            inventario[minimo] = temp;
        }
    }
    cout << "\nProductos ordenados por cantidad!" << endl;
}

// funcion para modificar cantidad con punteros
void modificarCantidad(Producto *p, int nuevaCantidad) {
    p->cantidad = nuevaCantidad;
    cout << "Cantidad actualizada para " << p->nombre << endl;
}

// funcion para agregar stock
void agregarStock(Producto *p, int cantidad) {
    p->cantidad += cantidad;
    cout << "Se agregaron " << cantidad << " unidades a " << p->nombre << endl;
}

int main() {
    // registro de 10 productos
    Producto inventario[10];
    
    inventario[0].id = 1;
    inventario[0].nombre = "Aceite Motor";
    inventario[0].precio = 350.00;
    inventario[0].cantidad = 45;
    
    inventario[1].id = 2;
    inventario[1].nombre = "Filtro Aire";
    inventario[1].precio = 180.50;
    inventario[1].cantidad = 30;
    
    inventario[2].id = 3;
    inventario[2].nombre = "Bateria 12V";
    inventario[2].precio = 1500.00;
    inventario[2].cantidad = 15;
    
    inventario[3].id = 4;
    inventario[3].nombre = "Llantas";
    inventario[3].precio = 2800.00;
    inventario[3].cantidad = 20;
    
    inventario[4].id = 5;
    inventario[4].nombre = "Bujias";
    inventario[4].precio = 85.00;
    inventario[4].cantidad = 60;
    
    inventario[5].id = 6;
    inventario[5].nombre = "Limpia Parabrisas";
    inventario[5].precio = 120.00;
    inventario[5].cantidad = 25;
    
    inventario[6].id = 7;
    inventario[6].nombre = "Filtro Aceite";
    inventario[6].precio = 95.00;
    inventario[6].cantidad = 40;
    
    inventario[7].id = 8;
    inventario[7].nombre = "Refrigerante";
    inventario[7].precio = 220.00;
    inventario[7].cantidad = 35;
    
    inventario[8].id = 9;
    inventario[8].nombre = "Balatas";
    inventario[8].precio = 450.00;
    inventario[8].cantidad = 18;
    
    inventario[9].id = 10;
    inventario[9].nombre = "Amortiguadores";
    inventario[9].precio = 1200.00;
    inventario[9].cantidad = 12;

// CONTINUA EN LA PARTE 2...

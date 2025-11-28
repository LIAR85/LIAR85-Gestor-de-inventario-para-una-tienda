//La aplicacion se subio a https://github.com/LIAR85/LIAR85-Gestor-de-inventario-para-una-tienda
//Luis ivan acuña resendez


#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
using namespace std;

// datos basicos del producto
struct Producto {
    int id;
    string nombre;
    float precio;
    int cantidad;
};

// muestra un producto en formato tabla
void mostrarProducto(Producto *p) {
    const int COL_ID = 6;
    const int COL_NOMBRE = 20;
    const int COL_PRECIO = 12;
    const int COL_CANTIDAD = 12;

    cout << left << setw(COL_ID) << "ID"
         << setw(COL_NOMBRE) << "NOMBRE"
         << setw(COL_PRECIO) << "PRECIO"
         << setw(COL_CANTIDAD) << "CANTIDAD" << endl;

    cout << left << setw(COL_ID) << p->id
         << setw(COL_NOMBRE) << p->nombre
         << setw(COL_PRECIO) << fixed << setprecision(2) << p->precio
         << setw(COL_CANTIDAD) << p->cantidad << endl;

    cout << defaultfloat; // resetea formato para futuras impresiones
    cout << string(60, '-') << endl << endl;
}

void mostrarTodos(Producto inventario[], int total) {
    cout << "\n=== INVENTARIO COMPLETO ===" << endl;
    for(int i = 0; i < total; i++) {
        mostrarProducto(&inventario[i]);
    }
}

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

void modificarCantidad(Producto *p, int nuevaCantidad) {
    p->cantidad = nuevaCantidad;
    cout << "Cantidad actualizada para " << p->nombre << endl;
}

void agregarStock(Producto *p, int cantidad) {
    p->cantidad += cantidad;
    cout << "Se agregaron " << cantidad << " unidades a " << p->nombre << endl;
}

int main() {
    // productos cargados en memoria
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
    
    int opcion = 0;
    int idBuscar;
    string nombreBuscar;
    int cantidadNueva;
    
    // ciclo del menu principal
    do {
        cout << "\n\n===== SISTEMA DE INVENTARIO =====" << endl;
        cout << "1. Mostrar todos los productos" << endl;
        cout << "2. Buscar producto por ID" << endl;
        cout << "3. Buscar producto por nombre" << endl;
        cout << "4. Ordenar por precio" << endl;
        cout << "5. Ordenar por cantidad" << endl;
        cout << "6. Modificar cantidad de producto" << endl;
        cout << "7. Agregar stock a producto" << endl;
        cout << "8. Salir" << endl;
        cout << "Elige una opcion: ";
        if(!(cin >> opcion)) {
            cout << "Entrada invalida, intenta otra vez" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        
        switch(opcion) {
            case 1:
                mostrarTodos(inventario, 10);
                break;
                
            case 2:
                cout << "Ingresa el ID a buscar: ";
                cin >> idBuscar;
                buscarPorID(inventario, 10, idBuscar);
                break;
                
            case 3:
                cout << "Ingresa el nombre a buscar: ";
                cin.ignore();
                getline(cin, nombreBuscar);
                buscarPorNombre(inventario, 10, nombreBuscar);
                break;
                
            case 4:
                ordenarPorPrecio(inventario, 10);
                mostrarTodos(inventario, 10);
                break;
                
            case 5:
                ordenarPorCantidad(inventario, 10);
                mostrarTodos(inventario, 10);
                break;
                
            case 6:
                cout << "Ingresa el ID del producto: ";
                cin >> idBuscar;
                for(int i = 0; i < 10; i++) {
                    if(inventario[i].id == idBuscar) {
                        cout << "Ingresa la nueva cantidad: ";
                        cin >> cantidadNueva;
                        modificarCantidad(&inventario[i], cantidadNueva);
                        break;
                    }
                }
                break;
                
            case 7:
                cout << "Ingresa el ID del producto: ";
                cin >> idBuscar;
                for(int i = 0; i < 10; i++) {
                    if(inventario[i].id == idBuscar) {
                        cout << "Cuantas unidades agregar?: ";
                        cin >> cantidadNueva;
                        agregarStock(&inventario[i], cantidadNueva);
                        break;
                    }
                }
                break;
                
            case 8:
                cout << "Saliendo del sistema..." << endl;
                break;
                
            default:
                cout << "Opcion no valida, intenta de nuevo" << endl;
        }
        
    } while(opcion != 8);
    
    return 0;
}

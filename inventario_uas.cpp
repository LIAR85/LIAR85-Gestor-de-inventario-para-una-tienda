#include <iostream>
#include <string>
using namespace std;

// estructura para productos
struct Producto {
    int id; // id del producto
    string nombre; // nombre
    float precio; // precio
    int cantidad; // cantidad
};

// muestra un producto
void mostrarProducto(Producto *p) {
    cout << "ID: " << p->id << endl;
    cout << "Nombre: " << p->nombre << endl;
    cout << "Precio: $" << p->precio << endl;
    cout << "Cantidad: " << p->cantidad << endl;
    cout << "-------------------" << endl;
}

// muestra todos los productos
void mostrarTodos(Producto inventario[], int total) {
    for(int i = 0; i < total; i++) {
        mostrarProducto(&inventario[i]);
    }
}

// busca por id
void buscarPorID(Producto inventario[], int total, int idBuscar) {
    bool encontrado = false;
    for(int i = 0; i < total; i++) {
        if(inventario[i].id == idBuscar) {
            mostrarProducto(&inventario[i]);
            encontrado = true;
            break;
        }
    }
    if(!encontrado) {
        cout << "No se encontro el producto con ID " << idBuscar << endl;
    }
}

// busca por nombre
void buscarPorNombre(Producto inventario[], int total, string nombreBuscar) {
    bool encontrado = false;
    for(int i = 0; i < total; i++) {
        if(inventario[i].nombre == nombreBuscar) {
            mostrarProducto(&inventario[i]);
            encontrado = true;
        }
    }
    if(!encontrado) {
        cout << "No se encontro el producto " << nombreBuscar << endl;
    }
}

// ordena por precio
void ordenarPorPrecio(Producto *inventario, int total) {
    for(int i = 0; i < total - 1; i++) {
        for(int j = 0; j < total - i - 1; j++) {
            if(inventario[j].precio > inventario[j + 1].precio) {
                Producto temp = inventario[j];
                inventario[j] = inventario[j + 1];
                inventario[j + 1] = temp;
            }
        }
    }
    cout << "Productos ordenados por precio!" << endl;
}

// ordena por cantidad
void ordenarPorCantidad(Producto *inventario, int total) {
    for(int i = 0; i < total - 1; i++) {
        int minimo = i;
        for(int j = i + 1; j < total; j++) {
            if(inventario[j].cantidad < inventario[minimo].cantidad) {
                minimo = j;
            }
        }
        if(minimo != i) {
            Producto temp = inventario[i];
            inventario[i] = inventario[minimo];
            inventario[minimo] = temp;
        }
    }
    cout << "Productos ordenados por cantidad!" << endl;
}

// modifica cantidad
void modificarCantidad(Producto *p, int nuevaCantidad) {
    p->cantidad = nuevaCantidad;
    cout << "Cantidad actualizada para " << p->nombre << endl;
}

// agrega stock
void agregarStock(Producto *p, int cantidad) {
    p->cantidad += cantidad;
    cout << "Se agregaron " << cantidad << " unidades a " << p->nombre << endl;
}

int main() {
    Producto inventario[10];
    inventario[0] = {1, "Aceite Motor", 350.00, 45};
    inventario[1] = {2, "Filtro Aire", 180.50, 30};
    inventario[2] = {3, "Bateria 12V", 1500.00, 15};
    inventario[3] = {4, "Llantas", 2800.00, 20};
    inventario[4] = {5, "Bujias", 85.00, 60};
    inventario[5] = {6, "Limpia Parabrisas", 120.00, 25};
    inventario[6] = {7, "Filtro Aceite", 95.00, 40};
    inventario[7] = {8, "Refrigerante", 220.00, 35};
    inventario[8] = {9, "Balatas", 450.00, 18};
    inventario[9] = {10, "Amortiguadores", 1200.00, 12};

    int opcion;
    do {
        cout << "\n===== SISTEMA DE INVENTARIO =====" << endl;
        cout << "1. Mostrar todos los productos" << endl;
        cout << "2. Buscar producto por ID" << endl;
        cout << "3. Buscar producto por nombre" << endl;
        cout << "4. Ordenar por precio" << endl;
        cout << "5. Ordenar por cantidad" << endl;
        cout << "6. Modificar cantidad de producto" << endl;
        cout << "7. Agregar stock a producto" << endl;
        cout << "8. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                mostrarTodos(inventario, 10);
                break;
            case 2: {
                int idBuscar;
                cout << "Ingresa el ID a buscar: ";
                cin >> idBuscar;
                buscarPorID(inventario, 10, idBuscar);
                break;
            }
            case 3: {
                string nombreBuscar;
                cout << "Ingresa el nombre a buscar: ";
                cin.ignore();
                getline(cin, nombreBuscar);
                buscarPorNombre(inventario, 10, nombreBuscar);
                break;
            }
            case 4:
                ordenarPorPrecio(inventario, 10);
                break;
            case 5:
                ordenarPorCantidad(inventario, 10);
                break;
            case 6: {
                int id;
                cout << "Ingresa el ID del producto: ";
                cin >> id;
                for(int i = 0; i < 10; i++) {
                    if(inventario[i].id == id) {
                        int nuevaCantidad;
                        cout << "Ingresa la nueva cantidad: ";
                        cin >> nuevaCantidad;
                        modificarCantidad(&inventario[i], nuevaCantidad);
                        break;
                    }
                }
                break;
            }
            case 7: {
                int id;
                cout << "Ingresa el ID del producto: ";
                cin >> id;
                for(int i = 0; i < 10; i++) {
                    if(inventario[i].id == id) {
                        int cantidad;
                        cout << "Cuantas unidades agregar?: ";
                        cin >> cantidad;
                        agregarStock(&inventario[i], cantidad);
                        break;
                    }
                }
                break;
            }
            case 8:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opcion no valida, intenta de nuevo" << endl;
        }
    } while(opcion != 8);

    return 0;
}

// ...CONTINUACION DE LA PARTE 1

    int opcion;
    int idBuscar;
    string nombreBuscar;
    int cantidadNueva;
    
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
        cin >> opcion;
        
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

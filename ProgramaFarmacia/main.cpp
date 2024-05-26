#include <iostream>
#include <fstream>
#include "Farmacia.h"

int main() {
    Farmacia farmacia;
    farmacia.cargarProductos("bodega.txt");

    bool ejecutando = true;
    while (ejecutando) {
        std::cout << "\n1. Mostrar Inventario\n";
        std::cout << "2. Agregar Cliente\n";
        std::cout << "3. Atender Cliente\n";
        std::cout << "4. Generar Venta\n";
        std::cout << "5. Guardar y Salir\n";
        std::cout << "Selecciona una opción: ";
        int opcion;
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                farmacia.mostrarInventario();
                break;
            case 2: {
                std::string nombre;
                int tipo;
                std::cout << "Nombre del cliente: ";
                std::cin >> nombre;
                std::cout << "Tipo de cliente (0: Normal, 1: Tercera Edad, 2: Discapacidad, 3: Embarazada): ";
                std::cin >> tipo;
                farmacia.agregarCliente(nombre, static_cast<TipoCliente>(tipo));
                break;
            }
            case 3:
                farmacia.atenderCliente();
                break;
            case 4: {
                Venta venta;
                int id, cantidad;
                while (true) {
                    std::cout << "ID del producto (0 para finalizar): ";
                    std::cin >> id;
                    if (id == 0) break;
                    std::cout << "Cantidad: ";
                    std::cin >> cantidad;
                    Producto* producto = farmacia.buscarProducto(id);
                    if (producto && producto->obtenerCantidad() >= cantidad) {
                        venta.agregarProducto(producto, cantidad);
                    } else {
                        std::cout << "Producto no encontrado o cantidad insuficiente.\n";
                    }
                }
                venta.generarBoleta();
                break;
            }
            case 5:
                farmacia.guardarProductos("bodega.txt");
                ejecutando = false;
                break;
            default:
                std::cout << "Opción no válida.\n";
                break;
        }
    }

    return 0;
}

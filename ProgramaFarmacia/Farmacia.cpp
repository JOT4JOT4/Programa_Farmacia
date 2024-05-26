#include "Farmacia.h"
#include <fstream>
#include <sstream>
#include <iostream>

Farmacia::~Farmacia() {
    for (auto& item : inventario) {
        delete item.second;
    }
}

void Farmacia::cargarProductos(const std::string& archivo) {
    std::ifstream file(archivo);
    std::string linea;
    while (std::getline(file, linea)) {
        std::istringstream ss(linea);
        int id, cantidad;
        double precio;
        std::string nombre, categoria, subcategoria;
        ss >> id >> nombre >> categoria >> subcategoria >> cantidad >> precio;
        inventario[id] = new Producto(id, nombre, categoria, subcategoria, cantidad, precio);
    }
}

void Farmacia::mostrarInventario() const {
    std::map<std::string, std::map<std::string, int>> inventarioPorCategoria;
    for (const auto& item : inventario) {
        inventarioPorCategoria[item.second->obtenerCategoria()][item.second->obtenerSubcategoria()] += item.second->obtenerCantidad();
    }

    for (const auto& categoria : inventarioPorCategoria) {
        std::cout << "Categoría: " << categoria.first << "\n";
        for (const auto& subcategoria : categoria.second) {
            std::cout << "  Subcategoría: " << subcategoria.first << " - Cantidad: " << subcategoria.second << "\n";
        }
    }
}

void Farmacia::agregarCliente(const std::string& nombre, TipoCliente tipo) {
    colaClientes.push(new Cliente(nombre, tipo));
}

void Farmacia::atenderCliente() {
    if (colaClientes.empty()) {
        std::cout << "No hay clientes en la cola.\n";
        return;
    }

    Cliente* cliente = colaClientes.top();
    colaClientes.pop();
    std::cout << "Atendiendo a cliente: " << cliente->obtenerNombre() << " con tipo: " << cliente->obtenerTipo() << "\n";
    delete cliente;
}

Producto* Farmacia::buscarProducto(int id) const {
    auto it = inventario.find(id);
    return (it != inventario.end()) ? it->second : nullptr;
}

void Farmacia::guardarProductos(const std::string& archivo) const {
    std::ofstream file(archivo);
    for (const auto& item : inventario) {
        file << item.second->obtenerId() << " "
             << item.second->obtenerNombre() << " "
             << item.second->obtenerCategoria() << " "
             << item.second->obtenerSubcategoria() << " "
             << item.second->obtenerCantidad() << " "
             << item.second->obtenerPrecio() << "\n";
    }
}

#ifndef FARMACIA_H
#define FARMACIA_H

#include <map>
#include <queue>
#include <string>
#include "Producto.h"
#include "Cliente.h"
#include "Venta.h"

struct ComparadorClientes {
    bool operator()(const Cliente* c1, const Cliente* c2) {
        return c1->obtenerTipo() < c2->obtenerTipo();
    }
};

class Farmacia {
private:
    std::map<int, Producto*> inventario;
    std::priority_queue<Cliente*, std::vector<Cliente*>, ComparadorClientes> colaClientes;

public:
    ~Farmacia();

    void cargarProductos(const std::string& archivo);
    void mostrarInventario() const;
    void agregarCliente(const std::string& nombre, TipoCliente tipo);
    void atenderCliente();
    Producto* buscarProducto(int id) const;
    void guardarProductos(const std::string& archivo) const;
};

#endif // FARMACIA_H

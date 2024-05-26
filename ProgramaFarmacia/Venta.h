#ifndef VENTA_H
#define VENTA_H

#include <vector>
#include <utility>
#include <iostream>
#include <iomanip>
#include "Producto.h"

class Venta {
private:
    std::vector<std::pair<Producto*, int>> productos;
    double total;

public:
    Venta();

    void agregarProducto(Producto* producto, int cantidad);
    void generarBoleta() const;
};

#endif // VENTA_H

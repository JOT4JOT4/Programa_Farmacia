#include "Venta.h"

Venta::Venta() : total(0) {}

void Venta::agregarProducto(Producto* producto, int cantidad) {
    productos.push_back({producto, cantidad});
    total += producto->obtenerPrecio() * cantidad;
    producto->actualizarCantidad(producto->obtenerCantidad() - cantidad);
}

void Venta::generarBoleta() const {
    std::cout << "Boleta de Venta\n";
    std::cout << "----------------------------------\n";
    for (const auto& item : productos) {
        double subtotal = item.first->obtenerPrecio() * item.second;
        std::cout << item.first->obtenerNombre() << " x" << item.second << " - $" << std::fixed << std::setprecision(2) << subtotal << "\n";
    }
    std::cout << "----------------------------------\n";
    std::cout << "Total: $" << std::fixed << std::setprecision(2) << total << "\n";
}

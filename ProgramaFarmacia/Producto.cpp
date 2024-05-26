#include "Producto.h"

Producto::Producto(int _id, const std::string& _nombre, const std::string& _categoria, const std::string& _subcategoria, int _cantidad, double _precio)
    : id(_id), nombre(_nombre), categoria(_categoria), subcategoria(_subcategoria), cantidad(_cantidad), precio(_precio) {}

int Producto::obtenerId() const { return id; }
const std::string& Producto::obtenerNombre() const { return nombre; }
const std::string& Producto::obtenerCategoria() const { return categoria; }
const std::string& Producto::obtenerSubcategoria() const { return subcategoria; }
int Producto::obtenerCantidad() const { return cantidad; }
double Producto::obtenerPrecio() const { return precio; }

void Producto::actualizarCantidad(int nuevaCantidad) { cantidad = nuevaCantidad; }

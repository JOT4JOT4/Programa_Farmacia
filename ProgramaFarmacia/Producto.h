#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

class Producto {
private:
    int id;
    std::string nombre;
    std::string categoria;
    std::string subcategoria;
    int cantidad;
    double precio;

public:
    Producto(int _id, const std::string& _nombre, const std::string& _categoria, const std::string& _subcategoria, int _cantidad, double _precio);

    int obtenerId() const;
    const std::string& obtenerNombre() const;
    const std::string& obtenerCategoria() const;
    const std::string& obtenerSubcategoria() const;
    int obtenerCantidad() const;
    double obtenerPrecio() const;

    void actualizarCantidad(int nuevaCantidad);
};

#endif // PRODUCTO_H

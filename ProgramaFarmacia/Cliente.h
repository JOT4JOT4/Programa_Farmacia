#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

enum TipoCliente {
    NORMAL,
    TERCERA_EDAD,
    DISCAPACIDAD,
    EMBARAZADA
};

class Cliente {
private:
    std::string nombre;
    TipoCliente tipo;

public:
    Cliente(const std::string& _nombre, TipoCliente _tipo);

    const std::string& obtenerNombre() const;
    TipoCliente obtenerTipo() const;
};

#endif // CLIENTE_H

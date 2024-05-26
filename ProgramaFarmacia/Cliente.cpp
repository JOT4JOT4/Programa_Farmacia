#include "Cliente.h"

Cliente::Cliente(const std::string& _nombre, TipoCliente _tipo) : nombre(_nombre), tipo(_tipo) {}

const std::string& Cliente::obtenerNombre() const { return nombre; }
TipoCliente Cliente::obtenerTipo() const { return tipo; }

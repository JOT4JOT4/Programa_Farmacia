###Equipo de Trabajo
- Nombre: Juan Pablo Vargas Corral
- Rut: 20.428.612-4
- Correo: Juan.vargas01@alumnos.ucn.cl

- Nombre: Cristobal Luna
- Rut: 21.006.280-7
- Correo: Cristobal.luna@alumnos.ucn.cl

# Info del Programa "Gestión de Farmacia"

Codigo para Ejecutar: "g++ -o farmacia main.cpp Producto.cpp Cliente.cpp Venta.cpp Farmacia.cpp"
Versión del Compilador utilizado "g++ (MinGW.org GCC-6.3.0-1) 6.3.0"

## Productos

Info de los productos cargados en el inventario al iniciar el programa.
## Para editar los productos, se pueden agregar a "bodega.txt" con el siguiente formato: ID,NOMBRE,CATEGORÍA,SUBCATEGORÍA,CANTIDAD,PRECIO

### Ejemplo:
ID: 1
Nombre: Paracetamol
Categoría: Medicamentos
Subcategoría: Analgesicos
Cantidad: 50
Precio: 1.50

## Clientes

Info de los clientes registrados en el sistema.

### Ejemplo:
Nombre: Juan Pérez
Tipo: Tercera Edad

## Programa

### Productos

- Los productos se cargan desde el archivo `bodega.txt`.
- Cada producto tiene un ID único, nombre, categoría, subcategoría, cantidad y precio.
- El inventario se puede consultar y modificar a través del programa. (Opción 1)

### Clientes

- Los clientes se registran y se manejan con prioridad según su tipo.
- Tipos de clientes:
  - Normal
  - Tercera Edad
  - Discapacidad
  - Embarazada

### Ventas

- Se pueden generar ventas agregando productos al carrito y generando una boleta.
- Los productos seleccionados se restan del inventario.

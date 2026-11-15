# Ejercicio 1: Validacion con excepciones
Pide una edad y un correo. Si el dato no es valido se lanza una excepcion propia, se captura en `main` y se vuelve a preguntar sin que el programa truene.

**Archivos:** `Excepciones.h` (`EdadInvalidaError`, `CorreoInvalidoError`) · `Validador.h/.cpp` (`validarEdad`, `validarCorreo`) · `main.cpp` (ciclo de captura)

- **Compilar:** `g++ -std=c++17 -Wall *.cpp -o programa.exe`
- **Ejecutar:** `./programa.exe`

```
Escribe tu edad: abc
  Edad invalida: "abc" no es un numero. Intenta de nuevo.
Escribe tu edad: 19
Escribe tu correo: luis@gmail
  Correo invalido: "luis@gmail" no tiene el formato usuario@dominio.com. Intenta de nuevo.
Escribe tu correo: luis@gmail.com

Datos registrados correctamente
```

**Tema de la unidad:** excepciones propias que heredan de `std::invalid_argument`, captura de `std::invalid_argument` y `std::out_of_range` de `std::stoi`, y validacion de formato con `std::regex`.

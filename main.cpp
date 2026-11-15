// Ejercicio 1: Validacion con excepciones
#include <iostream>
#include <string>
#include "Validador.h"
#include "Excepciones.h"

// Lee una linea del teclado. Regresa false si ya no hay entrada (Ctrl+Z / Ctrl+D).
bool leerLinea(const std::string& mensaje, std::string& destino) {
    std::cout << mensaje;
    return static_cast<bool>(std::getline(std::cin, destino));
}

int main() {
    std::cout << "=== 1. Validacion con excepciones ===" << std::endl;

    std::string entrada;
    int edad = 0;
    std::string correo;

    // Se repite la pregunta hasta que la edad sea valida
    while (true) {
        if (!leerLinea("Escribe tu edad: ", entrada)) {
            std::cout << "\nSe cerro la entrada antes de terminar." << std::endl;
            return 1;
        }
        try {
            edad = Validador::validarEdad(entrada);
            break;
        } catch (const EdadInvalidaError& e) {
            std::cout << "  Edad invalida: " << e.what() << ". Intenta de nuevo." << std::endl;
        }
    }

    // Se repite la pregunta hasta que el correo sea valido
    while (true) {
        if (!leerLinea("Escribe tu correo: ", entrada)) {
            std::cout << "\nSe cerro la entrada antes de terminar." << std::endl;
            return 1;
        }
        try {
            correo = Validador::validarCorreo(entrada);
            break;
        } catch (const CorreoInvalidoError& e) {
            std::cout << "  Correo invalido: " << e.what() << ". Intenta de nuevo." << std::endl;
        }
    }

    std::cout << "\nDatos registrados correctamente" << std::endl;
    std::cout << "  Edad:   " << edad << " anios" << std::endl;
    std::cout << "  Correo: " << correo << std::endl;
    return 0;
}

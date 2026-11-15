// Funciones de validacion: lanzan una excepcion si el dato no es valido
#ifndef VALIDADOR_H
#define VALIDADOR_H

#include <string>

class Validador {
public:
    static const int EDAD_MINIMA = 0;
    static const int EDAD_MAXIMA = 120;

    // Convierte el texto a entero. Lanza EdadInvalidaError si no se puede.
    static int validarEdad(const std::string& texto);

    // Regresa el correo sin espacios. Lanza CorreoInvalidoError si el formato es incorrecto.
    static std::string validarCorreo(const std::string& texto);

private:
    static std::string quitarEspacios(const std::string& texto);
};

#endif

// Excepciones propias del ejercicio de validacion
#ifndef EXCEPCIONES_H
#define EXCEPCIONES_H

#include <stdexcept>
#include <string>

// Se lanza cuando la edad no es un numero valido o esta fuera de rango
class EdadInvalidaError : public std::invalid_argument {
public:
    explicit EdadInvalidaError(const std::string& mensaje)
        : std::invalid_argument(mensaje) {}
};

// Se lanza cuando el correo no tiene el formato usuario@dominio.ext
class CorreoInvalidoError : public std::invalid_argument {
public:
    explicit CorreoInvalidoError(const std::string& mensaje)
        : std::invalid_argument(mensaje) {}
};

#endif

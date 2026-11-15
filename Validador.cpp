#include "Validador.h"
#include "Excepciones.h"
#include <regex>

std::string Validador::quitarEspacios(const std::string& texto) {
    const std::string blancos = " \t\r\n";
    std::size_t inicio = texto.find_first_not_of(blancos);
    if (inicio == std::string::npos) {
        return "";
    }
    std::size_t fin = texto.find_last_not_of(blancos);
    return texto.substr(inicio, fin - inicio + 1);
}

int Validador::validarEdad(const std::string& texto) {
    std::string limpio = quitarEspacios(texto);
    if (limpio.empty()) {
        throw EdadInvalidaError("la edad no puede estar vacia");
    }

    int edad = 0;
    std::size_t leidos = 0;
    try {
        edad = std::stoi(limpio, &leidos);
    } catch (const std::invalid_argument&) {
        // stoi no encontro ningun digito, por ejemplo "abc"
        throw EdadInvalidaError("\"" + limpio + "\" no es un numero");
    } catch (const std::out_of_range&) {
        // el numero no cabe en un int, por ejemplo "99999999999"
        throw EdadInvalidaError("el numero es demasiado grande");
    }

    // stoi acepta "25abc" y regresa 25, por eso se revisa que se haya leido todo
    if (leidos != limpio.size()) {
        throw EdadInvalidaError("\"" + limpio + "\" contiene caracteres que no son digitos");
    }
    if (edad < EDAD_MINIMA || edad > EDAD_MAXIMA) {
        throw EdadInvalidaError("la edad debe estar entre " + std::to_string(EDAD_MINIMA) +
                                " y " + std::to_string(EDAD_MAXIMA));
    }
    return edad;
}

std::string Validador::validarCorreo(const std::string& texto) {
    std::string limpio = quitarEspacios(texto);
    if (limpio.empty()) {
        throw CorreoInvalidoError("el correo no puede estar vacio");
    }
    if (limpio.find('@') == std::string::npos) {
        throw CorreoInvalidoError("al correo le falta el simbolo @");
    }

    // usuario@dominio.ext : sin espacios, un solo @ y al menos un punto en el dominio
    static const std::regex formato(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9-]+(\.[A-Za-z0-9-]+)*\.[A-Za-z]{2,}$)");
    if (!std::regex_match(limpio, formato)) {
        throw CorreoInvalidoError("\"" + limpio + "\" no tiene el formato usuario@dominio.com");
    }
    return limpio;
}

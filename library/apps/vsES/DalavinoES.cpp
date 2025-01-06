#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool verificarExtensaoSegura(const string& ext) {
    vector<std::string> extSegura = {
        ".txt", ".pdf", ".log", ".json", ".csv", ".md", ".xml", 
        ".html", ".rtf", ".yaml"
    };
    return find(extSegura.begin(), extSegura.end(), ext) != extSegura.end();
}

void exibirTermosDeUso() {
    cout << "\n\nTÉRMINOS DE USO DEL SOFTWARE 'DalavinoES' - LEA CUIDADOSAMENTE ANTES DE USAR\n";
    cout << "1. 'DalavinoES' es una aplicación desarrollada para mostrar el contenido de archivos.\n";
    cout << "2. Al usar este software, usted acepta no usarlo con fines ilegales, dañinos o maliciosos.\n";
    cout << "3. 'DalavinoES' no se hace responsable de ningún daño causado por los archivos analizados en el software, incluyendo, pero no limitado a, daños a su sistema, pérdida de datos o violaciones de privacidad.\n";
    cout << "4. El software puede realizar comprobaciones básicas en los archivos, pero esto no garantiza que el archivo esté libre de virus o malware. La detección de amenazas no es 100% segura, y el uso es bajo su propio riesgo.\n";
    cout << "5. 'DalavinoES' no recopila datos de los archivos analizados. Sin embargo, al usar el software, reconoce que el programa puede acceder al contenido de los archivos para mostrarlo y analizarlo.\n";
    cout << "6. El usuario es completamente responsable del uso del software y de las consecuencias del uso indebido de archivos, como la propagación de virus o la instalación de malware.\n";
    cout << "7. 'DalavinoES' puede actualizarse periódicamente. Cualquier cambio en los términos de uso será divulgado y, al continuar utilizando el software, usted acepta los nuevos términos.\n";
    cout << "8. Si no está de acuerdo con los términos de uso, debe dejar de usar el software inmediatamente.\n\n";
    cout << "¿Está de acuerdo con los términos de uso? (sí/no): ";
}

void criarArquivo(const string& nome, const string& ext) {
    ofstream novoArquivo(nome + ext);
    if (novoArquivo.is_open()) {
        cout << "Archivo creado con éxito. Escriba lo que desee y se guardará en el archivo. Para guardar el archivo (Escriba '@end' para finalizar):\n";
        string linha;
        while (true) {
            getline(cin, linha);
            if (linha == "@end") {
                break;
            }
            novoArquivo << linha << endl;
        }
        cout << "Contenido guardado en el archivo " << nome + ext << endl;
        novoArquivo.close();
    } else {
        cout << "Error al crear el archivo." << endl;
    }
}

int main() {
    int valor = 0;
    string ext;
    string nome;
    string linha;
    string ver;
    string saudacao = "Hola\nBienvenido a DalavinoES, un visor de archivos.\nEn resumen: ¡Esta aplicación muestra el código/texto dentro del archivo que elijas o crea un nuevo archivo!\n";

    cout << saudacao;
    cout << "\n versión: 1.2";

    exibirTermosDeUso();

    string resposta;
    cin >> resposta;
    transform(resposta.begin(), resposta.end(), resposta.begin(), ::tolower);
    if (resposta != "sí" && resposta != "si" && resposta != "s") {
        cout << "Debe aceptar los términos de uso para utilizar el software. Saliendo..." << endl;
        return 0;
    }

    while (true) {
        system("title DalavinoES");
        cout << "Elija una opción:\n";
        cout << "1 - Leer archivo\n";
        cout << "2 - Crear archivo\n";
        cout << "3 - Salir\n";
        cout << "Ingrese el número de la opción deseada: ";
        
        int opcao;
        cin >> opcao;
        cin.ignore();

        if (opcao == 1) {
            cout << "'@exit' / '@salir' para salir\n";
            cout << "Ingrese el nombre del archivo para leer.\n->";
            cin >> nome;

            transform(nome.begin(), nome.end(), nome.begin(), ::tolower);

            if (nome == "@salir" || nome == "@exit") {
                cout << "Saliendo..." << endl;
                break;
            }

            if (nome.find(".") == string::npos) {
                cout << "Ingrese la extensión del archivo: ";
                cin >> ext;
            } else {
                ext = nome.substr(nome.find_last_of("."));
                nome = nome.substr(0, nome.find_last_of("."));
            }

            ifstream arquivo(nome + ext);

            if (arquivo.is_open()) {
                cout << "\n\n" << nome;
                cout << "\n=========\n\n";
                while (getline(arquivo, linha)) {
                    cout << linha << endl;
                }
                cout << "\n=========\n\n";
                cout << "¿Desea activar el escaneo de virus? (sí/no): ";
                cin >> ver;
                transform(ver.begin(), ver.end(), ver.begin(), ::tolower);
                if (ver == "sí" || ver == "si" || ver == "s") {
                    valor = 0;
                    ifstream arquivo_verificacao(nome + ext);
                    while (getline(arquivo_verificacao, linha)) {
                        vector<string> palavrasChave = {
                            "virus", "malware", "destroy", "remove", "shutdown", "delete", "system32",
                            "spyware", "invade", "crash", "trace", "explode", "block", "ad", "reset",
                            "rd", "format", "false", "threat", "dangerous"
                        };
                        for (const auto& palavra : palavrasChave) {
                            if (linha.find(palavra) != string::npos) valor++;
                        }
                    }
                    cout << "Reportado: " << valor << " supuestas amenazas." << endl;
                    if (verificarExtensaoSegura(ext)) {
                        cout << "Es poco probable que este archivo dañe directamente el sistema a menos que contenga un enlace malicioso. Aun así, es bueno ser cauteloso." << endl;
                    }
                }
                arquivo.close();
            } else {
                cout << "Error al abrir el archivo. Por favor intente de nuevo." << endl;
            }
        } else if (opcao == 2) {
            cout << "Ingrese el nombre del archivo que desea crear:\n->";
            cin >> nome;
            transform(nome.begin(), nome.end(), nome.begin(), ::tolower);
            cout << "Ingrese la extensión del archivo (por ejemplo, .txt, .md, etc): ";
            cin >> ext;
            criarArquivo(nome, ext);
        } else if (opcao == 3) {
            cout << "Saliendo..." << endl;
            break;
        } else {
            cout << "Opción no válida. Por favor intente de nuevo.\n";
            break;
        }
    }

    return 0;
}
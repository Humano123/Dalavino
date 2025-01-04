#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string nome = "CMDT.txt";
    string linha;
    string cmdnome = "start notepad.exe " + nome;
    string copiler;

    ifstream arquivo("CMDT.txt");

    if (!arquivo.is_open()) {
        ofstream code("CMDT.txt");
        system(cmdnome.c_str());
        arquivo.close();
    }

    while (true) {
        cout << "-";
            cin >> copiler;

        if (copiler == "stop") {
            cout << "Encerrando o programa..." << endl;
            break;
        }

        if (copiler == "init") {
            arquivo.clear(); // Reseta o estado do arquivo
            arquivo.seekg(0, ios::beg); // Volta para o início do arquivo

            system("cls");
            while (getline(arquivo, linha)) {
                if (linha.find("s.") == 0) {
                    string comando = linha.substr(2);
                    string executar = "start " + comando;
                    system(executar.c_str());
                } else if (linha.find("t.") == 0) {
                    string comandoT = linha.substr(2);
                    cout << comandoT << endl;
                } else if (linha.find(".shutdown") == 0) {
                    system("shutdown /s /t 0");
                } else if (linha.find(".dir") == 0) {
                    system("dir");
                } else if (linha.find("cl.") == 0) {
                    string comandoCL = linha.substr(2);
                    string executarCL = "color " + comandoCL;
                    system(executarCL.c_str());
                } else {
                    cout << "Nenhum comando executado!" << endl;
                }
            }
        } else {
            cout << "Comando inválido! Tente novamente." << endl;
        }
    }

    return 0;
}
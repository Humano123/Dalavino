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
    cout << "\n\n'DalavinoEN' SOFTWARE TERMS OF USE - PLEASE READ CAREFULLY BEFORE USING\n";
    cout << "1. 'DalavinoEN' is an application developed to display file contents.\n";
    cout << "2. By using this software, you agree not to use it for illegal, harmful, or malicious purposes.\n";
    cout << "3. 'DalavinoEN' is not responsible for any damage caused by files analyzed in the software, including, but not limited to, damage to your system, data loss, or privacy breaches.\n";
    cout << "4. The software can perform basic checks on files, but this does not guarantee that the file is free of viruses or malware. Threat detection is not 100% secure, and usage is at your own risk.\n";
    cout << "5. 'DalavinoEN' does not collect data from the analyzed files. However, by using the software, you acknowledge that the program may access the content of the files for display and analysis.\n";
    cout << "6. The user is entirely responsible for using the software and the consequences of misuse of files, such as spreading viruses or installing malware.\n";
    cout << "7. 'DalavinoEN' may be updated periodically. Any changes to the terms of use will be disclosed, and by continuing to use the software, you agree to the new terms.\n";
    cout << "8. If you do not agree with the terms of use, you must stop using the software immediately.\n\n";
    cout << "Do you agree with the terms of use? (yes/no): ";
}

void criarArquivo(const string& nome, const string& ext) {
    ofstream novoArquivo(nome + ext);
    if (novoArquivo.is_open()) {
        cout << "File successfully created. Write whatever you want, and it will be saved in the file. To save the file (Type '@end' to finish):\n";
        string linha;
        while (true) {
            getline(cin, linha);
            if (linha == "@end") {
                break;
            }
            novoArquivo << linha << endl;
        }
        cout << "Content saved to the file " << nome + ext << endl;
        novoArquivo.close();
    } else {
        cout << "Error creating the file." << endl;
    }
}

int main() {
    int valor = 0;
    string ext;
    string nome;
    string linha;
    string ver;
    string saudacao = "Hi\nWelcome to DalavinoEN, a file viewer.\nIn short: This application shows the code/text inside the file you choose or creates a new file!\n";

    cout << saudacao;
    cout << "\n Version: 1.2";

    exibirTermosDeUso();

    string resposta;
    cin >> resposta;
    transform(resposta.begin(), resposta.end(), resposta.begin(), ::tolower);
    if (resposta != "yes" && resposta != "y") {
        cout << "You must agree to the terms of use to use the software. Exiting..." << endl;
        return 0;
    }

    while (true) {
        system("title DalavinoEN");
        cout << "Choose an option:\n";
        cout << "1 - Read file\n";
        cout << "2 - Create file\n";
        cout << "3 - Exit\n";
        cout << "Enter the number of the desired option: ";
        
        int opcao;
        cin >> opcao;
        cin.ignore();

        if (opcao == 1) {
            cout << "'@exit' / '@sair' to exit\n";
            cout << "Enter the name of the file to read.\n->";
            cin >> nome;

            transform(nome.begin(), nome.end(), nome.begin(), ::tolower);

            if (nome == "@sair" || nome == "@exit") {
                cout << "Exiting..." << endl;
                break;
            }

            if (nome.find(".") == string::npos) {
                cout << "Enter the file extension: ";
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
                cout << "Do you want to activate the virus scan? (yes/no): ";
                cin >> ver;
                transform(ver.begin(), ver.end(), ver.begin(), ::tolower);
                if (ver == "yes" || ver == "y") {
                    valor = 0;
                    ifstream arquivo_verificacao(nome + ext);
                    while (getline(arquivo_verificacao, linha)) {
                        vector<string> palavrasChave = {
                            "virus", "malware", "destruir", "remover", "desligar", "deletar", "system32",
                            "spyware", "invadir", "derrubar", "rastrear", "explodir", "excluir", "remove",
                            "destroy", "shutdown", "del", "fake", "falso", "ad", "anuncio", "block", "blocked",
                            "bloquear", "guardar", "ameaça", "ameaçar", "iniciar", "reset", "rd", "copy", "crypto",
                            "format", "formata", "inutilizar", "false", "exec", "eval", "system", "os.system", "subprocess",
                            "popen", "cmd.exe", "/bin/bash", "PowerShell", "base64_decode", "rot13", "str_rot13", "gzinflate",
                            "gzdecode", "unserialize", "decode", "wget", "curl", "ftp", "sftp", "http.get", "socket", "connect",
                            "bind", "payload", "chmod", "chown", "unlink", "rm -rf", "fopen", "read", "write", "keylogger",
                            "reverse_shell", "trojan", "virus", "spyware", "ransomware", "encrypt", "decrypt", "AES", "RSA",
                            "blowfish", "hash", "md5", "sha1", "sha256", "http://", "https://", "regedit", "Taskkill",
                            "netstat", "schtasks", "cron", "sudo", "iptables", "killall"
                        };
                        for (const auto& palavra : palavrasChave) {
                            if (linha.find(palavra) != string::npos) valor++;
                        }
                    }
                    cout << "Reported: " << valor << " alleged threats." << endl;
                    if (verificarExtensaoSegura(ext)) {
                        cout << "This file is unlikely to directly damage the system unless it contains a malicious link inside. Still, it's good to be cautious." << endl;
                    }
                }
                arquivo.close();
            } else {
                cout << "Error opening the file. Please try again." << endl;
            }
        } else if (opcao == 2) {
            cout << "Enter the name of the file you want to create:\n->";
            cin >> nome;
            transform(nome.begin(), nome.end(), nome.begin(), ::tolower);
            cout << "Enter the file extension (e.g., .txt, .md, etc): ";
            cin >> ext;
            criarArquivo(nome, ext);
        } else if (opcao == 3) {
            cout << "Exiting..." << endl;
            break;
        } else {
            cout << "Invalid option. Please try again.\n";
            break;
        }
    }

    return 0;
}
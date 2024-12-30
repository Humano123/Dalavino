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
    //só pra eu não levar um processinho
    cout << "\n\nTERMO DE USO DO SOFTWARE 'Dalavino' - LEIA ATENTAMENTE ANTES DE UTILIZAR\n";
    cout << "1. O 'Dalavino' é um aplicativo desenvolvido para mostrar o conteúdo de arquivos.\n";
    cout << "2. Ao utilizar este software, você concorda em não usá-lo para fins ilegais, prejudiciais ou maliciosos.\n";
    cout << "3. O 'Dalavino' não se responsabiliza por qualquer dano causado por arquivos analisados no software, incluindo, mas não se limitando a, danos ao seu sistema, perda de dados ou invasões de privacidade.\n";
    cout << "4. O software pode realizar verificações básicas em arquivos, mas isso não garante que o arquivo esteja livre de vírus ou malwares. A verificação de ameaças não é 100% segura e o uso é por sua conta e risco.\n";
    cout << "5. O 'Dalavino' não coleta dados dos arquivos analisados. No entanto, ao usar o software, você reconhece que o programa poderá acessar o conteúdo dos arquivos para exibição e análise.\n";
    cout << "6. O usuário é inteiramente responsável pelo uso do software e pelas consequências do uso indevido de arquivos, como disseminação de vírus ou instalação de malwares.\n";
    cout << "7. O 'Dalavino' pode ser atualizado periodicamente. Quaisquer mudanças nos termos de uso serão divulgadas, e ao continuar a usar o software, você concorda com os novos termos.\n";
    cout << "8. Caso você não concorde com os termos de uso, deve interromper imediatamente o uso do software.\n\n";
    cout << "Você concorda com os termos de uso? (sim/nao): ";
}

void criarArquivo(const string& nome, const string& ext) {
    ofstream novoArquivo(nome + ext);
    if (novoArquivo.is_open()) {
        cout << "Arquivo criado com sucesso. Escreva oque quiser, que será salvo no arquivo, para salvar no arquivo (Digite '@fim' para finalizar):\n";
        string linha;
        while (true) {
            getline(cin, linha);
            if (linha == "@fim") {
                break;
            }
            novoArquivo << linha << endl;
        }
        cout << "Conteúdo salvo no arquivo " << nome + ext << endl;
        novoArquivo.close();
    } else {
        cout << "Erro ao criar o arquivo." << endl;
    }
}

int main() {
    int valor = 0;
    string ext;
    string nome;
    string linha;
    string ver;
    string saudacao = "Oii\nBem-Vindo(a) ao Dalavino, um mostrador de arquivos.\nResumindo: Esse aplicativo mostra o código/texto dentro do arquivo que você escolher ou cria um novo arquivo!\n";

    cout << saudacao;

    exibirTermosDeUso();

    string resposta;
    cin >> resposta;
    transform(resposta.begin(), resposta.end(), resposta.begin(), ::tolower);
    if (resposta != "sim" && resposta != "s") {
        //não erre, fazendo favor
        cout << "Você deve concordar com os termos de uso para utilizar o software. Saindo..." << endl;
        return 0;
    }

    while (true) {
        system("title Dalavino");
        cout << "Escolha uma opção:\n";
        cout << "1 - Ler arquivo\n";
        cout << "2 - Criar arquivo\n";
        cout << "3 - Sair\n";
        cout << "Digite o número da opção desejada: ";
        
        int opcao;
        cin >> opcao;
        cin.ignore();

        if (opcao == 1) {
            cout << "'@sair' / '@exit' para sair\n";
            cout << "Digite o nome do arquivo para ler.\n->";
            cin >> nome;

            transform(nome.begin(), nome.end(), nome.begin(), ::tolower);

            if (nome == "@sair" || nome == "@exit") {
                cout << "Saindo..." << endl;
                break;
            }

            if (nome.find(".") == string::npos) {
                cout << "Digite a extensão do arquivo: ";
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
                cout << "Deseja ativar a verificação de vírus? (sim/nao): ";
                cin >> ver;
                transform(ver.begin(), ver.end(), ver.begin(), ::tolower);
                if (ver == "sim" || ver == "s") {
                    valor = 0;
                    ifstream arquivo_verificacao(nome + ext);
                    while (getline(arquivo_verificacao, linha)) {
                        vector<string> palavrasChave = { //palavras chaves
                            "virus", "malware", "destruir", "remover", "desligar", "deletar", "system32",
                            "spyware", "invadir", "derrubar", "rastrear", "explodir", "excluir", "remove",
                            "destroy", "shutdown", "del", "fake", "falso", "ad", "anuncio", "block", "blocked",
                            "bloquear", "guardar", "ameaça", "ameaçar", "iniciar", "reset", "rd", "copy", "crypto",
                            "format", "formata", "inutilizar", "false"
                        };
                        for (const auto& palavra : palavrasChave) {
                            if (linha.find(palavra) != string::npos) valor++;
                        }
                    }
                    cout << "Relatados: " << valor << " supostas ameaças." << endl;
                    if (verificarExtensaoSegura(ext)) {
                        cout << "Possivelmente isso não pode danificar diretamente, apenas se tiver um link malicioso dentro, mas é bom se prevenir." << endl;
                    }
                }
                arquivo.close();
            } else {
                cout << "Erro ao abrir o arquivo. Tente novamente." << endl;
            }
        } else if (opcao == 2) {
            cout << "Digite o nome do arquivo que deseja criar:\n->";
            cin >> nome;
            transform(nome.begin(), nome.end(), nome.begin(), ::tolower);
            cout << "Digite a extensão do arquivo (ex: .txt, .md, etc): "; //sim
            cin >> ext;
            criarArquivo(nome, ext);
        } else if (opcao == 3) {
            cout << "Saindo..." << endl;
            break;
        } else {
            cout << "Opção inválida. Tente novamente.";
            break;
        }
    }

    return 0;
}
//DEMOREI PRA CARAMBA PRA FAZER A VERIFICAÇÃO DE VIRUS, FOI UM SACRIFICIO, MAS CONSEGUI!!!!
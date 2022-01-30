#include "../headers/hospital.hpp"
#include <vector>

std::vector<std::string> split(const std::string& str, char c) {
    int last_char = 0;
    std::vector<std::string> out;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == c) {
            out.push_back(str.substr(last_char, i - last_char));
            last_char = i + 1;
        } else if (i == str.size() - 1) {
            out.push_back(str.substr(last_char, str.size() - last_char));
        }
    }
    
    return out;
}

int main() {
    Hospital hospital;

    while (true) {
        std::string cmd;
        std::cout << "$ ";
        std::cin >> cmd;
        std::cin.ignore();
        
        try {
            if (cmd == "addPacs" || cmd == "ap") {
                std::string line;
                std::getline(std::cin, line);
                auto pacientes = split(line, ' ');
                for (auto& paciente : pacientes) {
                    auto terms = split(paciente, '-');
                    hospital.add_paciente(terms[0], terms[1]);
                }
            } else if (cmd == "addMeds" || cmd == "am") {
                std::string line;
                std::getline(std::cin, line);
                auto medicos = split(line, ' ');
                for (auto& medico : medicos) {
                    auto terms = split(medico, '-');
                    hospital.add_medico(terms[0], terms[1]);
                }
            } else if (cmd == "tie" || cmd == "t") {
                std::string line;
                std::getline(std::cin, line);
                auto args = split(line, ' ');
                std::string medico = args[0];
                args.erase(args.begin());
                for (auto& paciente : args) {
                    hospital.vincular(medico, paciente);
                }
            } else if (cmd == "rmp") {
                std::string nome;
                std::cin >> nome;
                hospital.remover_paciente(nome);
            } else if (cmd == "rmm") {
                std::string nome;
                std::cin >> nome;
                hospital.remover_medico(nome);
            } else if (cmd == "show" || cmd == "s") {
                std::cout << hospital << std::endl;
            } else if (cmd == "clear" || cmd == "c") {
                #if defined(_WIN32) || defined(_WIN64)
                    std::system("cls");
                #else
                    std::system("clear");
                #endif
            } else if (cmd == "exit" || cmd == "e") {
                break;
            } else {
                throw std::string("fail: comando invalido");
            }
        } catch (std::string& error) {
            std::cout << error << std::endl;
        }
    }
}
/* - Aplicativo Quark Bank Versao final, eu espero!! - */

// Inclusao de bibliotecas.
#include <iostream>
#include <locale>
# include <Windows.h> // Pesquisar como utilizar a funcao sleep sem ser com o 
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <conio.h> 
#include <unistd.h>
#include <cstring>

// Estrutura de usuarios na aplicação.
struct Usuarios{
    std::string UserNome;
    std::string UserLogin;
    std::string UserSenha;
    float UserSaldo;
};

/* - Areas dos elementos globais - */

// variáveis referente a função de login.
std::string LoginLogar, SenhaLogar;

// variáveis referente a função de Registrar usuarios.
std::string LoginRegistrar, SenhaRegistrar, NomeRegistrar;

// variaveis referentes a funcao do usuario logado.
std::string NomeUserEncontrado, LoginUserEncontrado, SenhaUserEncontrado;

float SaldoUserEncontrado;

/* Vetor que está sendo utilizado como banco de dados para armazenar usuários */
std::vector<Usuarios>DatabaseUsers;

/* - Areas das funcoes - */

/*Funcao para verificar se o usuario existe no banco de dados */
bool UsuarioExiste(std::string LoginLogar, std::string SenhaLogar){
        for(size_t i = 0; i < DatabaseUsers.size(); i++){
            if(DatabaseUsers[i].UserLogin == LoginLogar && DatabaseUsers[i].UserSenha == SenhaLogar){

                    NomeUserEncontrado = DatabaseUsers[i].UserNome;
                    LoginUserEncontrado = DatabaseUsers[i].UserLogin;
                    SenhaUserEncontrado = DatabaseUsers[i].UserSenha;
                    SaldoUserEncontrado = DatabaseUsers[i].UserSaldo;

                return true;
            }
        }
        return false;
}

/* Função para verificar se um login já existe no banco de dados */
bool LoginExiste(std::string LoginRegistrar){
    for(size_t i = 0; i < DatabaseUsers.size(); i++){
        if(DatabaseUsers[i].UserLogin == LoginRegistrar){
            return true;
        }
    }
}

/* Função para quando o usuário logar no aplicativo */
void UsuarioLogado(bool UsuarioLogadoToken){

    UsuarioLogadoToken = true;

    int ContaEscolha;
    
    while(UsuarioLogadoToken == true){
        
        std::cout << "- x - Quark Bank App - x - \n";

        std::cout << "" << std::endl;

        std::cout << "Ola, " << NomeUserEncontrado << std::endl;
        std::cout << "Saldo disponivel: " << SaldoUserEncontrado << std::endl;

        std::cout << "" << std::endl;

        std::cout << "Menu: " << std::endl;

        std::cout << "" << std::endl;

        std::cout << "1 . Extrato" << std::endl;
        std::cout << "2 . Fazer pagamento" << std::endl;
        std::cout << "3 . Adicionar saldo" << std::endl;
        std::cout << "4 . Investimento" << std::endl;
        std::cout << "5 . Informacoes da conta" << std::endl;
        std::cout << "6 . Sair" << std::endl;

        std::cout << "" << std::endl;

        std::cout << "Escolha uma opcao: ";
        std::cin >> ContaEscolha;

        switch (ContaEscolha)
        {
        case 1:
            break;

        case 2:
            break;

        case 3:
            break;

        case 4:
            break;

        case 5:
            break;

        case 6:

                system("cls");

                std::cout << "Operacoes sendo encerradas..." << std::endl;

                sleep(2);

                UsuarioLogadoToken = false;
                
            break;
        
        default:
            break;
        }

    }
}

/* Função na hora do usuário logar para ver se o mesmo possui conta no aplicativo */
int Logar(){

    system("cls");

        std::cout << "Digite um login: ";
        std::cin >> LoginLogar;

        std::cout << "Digite uma senha: ";
        std::cin >> SenhaLogar; 

        sleep(2);

            if(LoginLogar.size() == 0 || SenhaLogar.size() == 0){

                std::cout << "Vazio games!!";

                exit(0);

            }else{

                bool Existe; 

                Existe = UsuarioExiste(LoginLogar, SenhaLogar);

                sleep(2);
            
                    if(Existe != true){

                        while(Existe != true){

                            system("cls");

                            std::cout << "Login e/ ou senha incorretos, tente novamente ou selecione uma nova opcao. \n";

                            sleep(2);

                            system("cls");

                            std::cout << "Digite um login: ";
                            std::cin >> LoginLogar;

                            std::cout << "Digite uma senha: ";
                            std::cin >> SenhaLogar; 

                            Existe = UsuarioExiste(LoginLogar, SenhaLogar);

                            sleep(2);

                        }
                    }
                    
                system("cls");

                bool UsuarioLogadoToken = 0;
                UsuarioLogado(UsuarioLogadoToken);
            }
            
    return 0;
}

/* Auto explicativo contudo apenas irá o que foi digitado nos campos da função CriarContaUsuario e irá registrar no banco de dados */
bool RegistrarUsuario(){

    Usuarios NewUser;

    NewUser.UserNome = NomeRegistrar;
    NewUser.UserLogin = LoginRegistrar;
    NewUser.UserSenha = SenhaRegistrar;
    NewUser.UserSaldo = 0;

    DatabaseUsers.push_back(NewUser);

    return true;

}

/* Auto explicativo contudo irá interromper imediatamente o algoritmo se for chamada */
void FecharApp(){

    std::cout << "Fechando Quark Bank App... \n";
    sleep(3);

    exit(0);
}

/* Irá solicitar ao usuário para informar os seus dados para registro */
void CriarContaUsuario(){

system("cls");

            std::cout << "Digite seu nome: ";
            std::cin >> NomeRegistrar;

            std::cout << "Crie um login: ";
            std::cin >> LoginRegistrar;

            bool LoginExisteVar;

            LoginExisteVar = LoginExiste(LoginRegistrar);

            if(LoginExisteVar == true){

                do {

                    sleep(3);

                    std::cout << "Ja posssuimos esse login em nossa base de dados, favor escolha outro... \n";

                    sleep(3);

                    std::cout << "Crie um login: ";
                    std::cin >> LoginRegistrar;

                    LoginExisteVar = LoginExiste(LoginRegistrar);

                } while(LoginExisteVar != false);
            }

            std::cout << "Crie uma senha: ";
            std::cin >> SenhaRegistrar;

            std::cout << "" << std::endl;
}

/* Funcoes de um usuario logado */

/* Função principal */
int main(){

    Usuarios NewUser;

    NewUser.UserNome = "Fernando";
    NewUser.UserLogin = "@fern";
    NewUser.UserSenha = "123";
    NewUser.UserSaldo = 1500;
    
    DatabaseUsers.push_back(NewUser);
    
    NewUser.UserNome = "Administrador";
    NewUser.UserLogin = "@admin";
    NewUser.UserSenha = "admin";
    NewUser.UserSaldo = 150000;
    
    DatabaseUsers.push_back(NewUser);

    std::cout << "Open App Quark Bank..." << std::endl;

    sleep(3);

    system("cls");

    std::cout << "-- Tela de login bala -- \n";
    std::cout << "" << std::endl;
    std::cout << "1 . Logar conta.. \n";
    std::cout << "2 . Nao possui conta..\n";
    std::cout << "3 . Sair.. \n";

    std::cout << "" << std::endl;

    int MenuInicial;

    Opcaodefault:

    std::cout << "Escolha uma opcao: ";
    std::cin >> MenuInicial;

    // Logica das opcoes da tela inicial do APP.
    switch (MenuInicial){

    case 1: // Logar.
            Logar();
        break;

    case 2: // Registrar.

            char MudarAlgo;

            do{

                CriarContaUsuario();

                std::cout << "Desenha mudar algo (S/ N)? ";

                std::cin >> MudarAlgo;

            } while(MudarAlgo == 'S' || MudarAlgo == 's');

            sleep(2);

            bool DeuCertoGames;

            DeuCertoGames = RegistrarUsuario();

            sleep(2);

            if (DeuCertoGames == true){

                sleep(2);

                std::cout << "Conta criada com sucesso, redirecionando para a tela de login..\n";

                sleep(3);

            }else{
                
                sleep(2);

                std::cout << "Houve um problema no processo de registro, favor tente novamente...\n";
            }
            
            Logar();

        break;

    case 3:

            system("cls");

            FecharApp();

        break;
    
    default:

            do{
                MenuInicial = 0;

                std::cout << "Opcao invalida, por favor escolha novamente:  \n";

                std::cout << "" << std::endl;

                std::cout << "1 . Logar conta.. \n";
                std::cout << "2 . Nao possui conta..\n";
                std::cout << "3 . Sair.. \n";

                std::cout << "" << std::endl;

                goto Opcaodefault;

            } while ((MenuInicial != 1) && (MenuInicial != 2) && (MenuInicial != 3));

        break;
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <time.h>

using namespace std;

void menu();
void limpa_tela(){
    system("cls");
}
void inicia_tabuleiro(char tabuleiro [10][10],char mascara [10][10]){
    int linha, coluna;
    for(linha =0;linha <10;linha++){
            for(coluna =0; coluna <10;coluna++){
                tabuleiro[linha][coluna] ='A';
                mascara[linha][coluna] ='*';
            }
    }
}

void exibemapa(){
        int cont= 0;
    for (cont =0;cont <10; cont++){
            if (cont == 0){
                cout<< "     ";
            }
        cout<<cont<<" ";
    }
    cout<<"\n";
    for (cont =0;cont <10; cont++){
            if (cont == 0){
                cout<< "     ";
            }
        cout<<"| ";
    }
        cout <<"\n";
}

void exibetabuleiro(char tabuleiro[10][10], char mascara[10][10], bool mostragabarito){



    int linha, coluna;
    for(linha =0;linha <10;linha++){
            cout<<linha<< " - ";
            for(coluna =0; coluna <10;coluna++){

            cout<<" "<<mascara[linha][coluna];
            }
        cout <<"\n";
    }
    if (mostragabarito == false){

        for(linha =0;linha <10;linha++){
            for(coluna =0; coluna <10;coluna++){

            cout<<" "<<tabuleiro[linha][coluna];
            }
            cout <<"\n";
        }
    }


}

void posicionabarcos(char tabuleiro[10][10]){

        int cont, quantidade =10,quantidadeposicionada =0;

      ///Verifica se já posicionou todos os barcos
        while(quantidadeposicionada<quantidade){

            int linhaaleatoria=rand()%10;
            int colunaaleatoria=rand()%10;

            if(tabuleiro[linhaaleatoria][colunaaleatoria] = 'A'){

                ///Posiciona 10 barcos aleatorios
                tabuleiro[linhaaleatoria][colunaaleatoria] = 'N';

                ///Aumenta o numero de barcos posicionados
                quantidadeposicionada++;

            }

            ///Posiciona os barcos aleatoriamente


        }



}

void verificatiro(char tabuleiro[10][10],int linhajogada ,int colunajogada,int *pontos, string *mensagem){
    switch (tabuleiro[linhajogada][colunajogada]){
        case 'N':
            *pontos = *pontos+10;
            *mensagem = "Voca acertou uma embarcacao pequena! (+10 pts)";
            break;
        case 'A':
            *mensagem = "Voce acertou a agua";
            break;

    }


}
void about(){
    cout<< "\n Este jogo foi desenvolvido na linguagem de C++ por Matheus Farias Freitas\n";
    cout<< "O objetivo principal da atividade foi o aprendizado e desenvolvimento logico do programados, \nsendo assim pos conclusao do projeto, as metas foram batidas com sucesso.";
    cout<<endl;
    cout<<"\nVOLTANDO AO MENU...\n";
    menu();
}
void jogo(string player){
    char tabuleiro [10][10],mascara [10][10];               ///Tabuleiro do jogo
    int linha, coluna;                                      ///Auxiliar de navegação
    int linhajogada, colunajogada;                          ///Posicao escolhida peolo jogo
    int estadodejogo =1;                                    /// 1 = jogo acontecendo / 0 = Fim de jogo
    int pontos = 0;                                         ///pontos acrescentados
    int tentativas =0, maximodetentativas = 5;              ///tentativas do jogador
    int opcao;                                              ///opcoes de fim de jogo

    string mensagem = "";                 ///mensagemd e feedback para o jogador





    ///Inicia o tabuleiro com água

    inicia_tabuleiro(tabuleiro, mascara);

    ///Posiciona barcos aleaotoriamente

    posicionabarcos(tabuleiro);

    while(tentativas < maximodetentativas){

        limpa_tela();


        exibemapa();


        exibetabuleiro(tabuleiro,mascara,true);
        cout <<"\nPontos: "<<pontos<< "\nTentativas restantes: "<<maximodetentativas - tentativas;
        cout <<"\n"<<mensagem;

        ///vericacao de dados
        int linhajogada =-1;
        int colunajogada = -1;

        while ((linhajogada <0 || colunajogada <0)|| (linhajogada >9 || colunajogada >9)){
        cout<< "\n "<<player<<", Digite uma linha.. \n";
        cin>> linhajogada;
        cout<<"\n"<<player<<", Digite uma coluna..\n";
        cin>>colunajogada;

        }

        cout<< "\n "<<player<<", Digite uma linha.. \n";
        cin>> linhajogada;
        cout<<"\n"<<player<<", Digite uma coluna..\n";
        cin>>colunajogada;


    ///Verifica a quantidade de pontos a add


    verificatiro(tabuleiro,linhajogada,colunajogada, &pontos,&mensagem);

    ///Revela o que está no tabuleiro
    mascara[linhajogada][colunajogada] = tabuleiro[linhajogada][colunajogada];

    tentativas++;
    }

    cout<< "Fim de jogo, como deseja prosseguir? \n";
    cout <<"\n1 - Jogar novamente";
    cout <<"\n2 - Ir ao menu";
    cout <<"\n3 - Sair";
    cin >> opcao;
    switch (opcao){
        case 1:
            jogo(player);
            break;
        case 2:
            menu();
            break;
        case 3:
            break;
    }
}

void menu (){
    //opcao escolhida pelo usuário
    int opcao = 0;

    string player;
    while(opcao <1 || opcao >3 ){

        cout<< "Bem vindo ao Jogo"<<player;

        cout<< "\nOpcao - 01 Jogar";
        cout<< "\nOpcao - 02 Sobre";
        cout<< "\nOpcao - 03 Sair";
        cout <<"\nEscolha uma opcao e tecle ENTER: ";
        cin>> opcao;

        switch(opcao){
            //inicia o jogo
        case 1:
            cout <<"Jogo iniciado..\n";
            cout <<"Qual o seu nickname? \n";
            cin>> player;
            jogo(player);
            break;
        case 2:
            cout <<"Informacoes do jogo..";
            about();
            break;
        case 3:
            cout <<"Saindo do jogo, ate logo..";
            break;
        }

    }

}

int main(){

    ///Gera valor aleatório
    srand((unsigned) time (NULL));

    menu();

    return 0;
}

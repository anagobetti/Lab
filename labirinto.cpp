#include "labirinto.hpp"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>


labirinto::labirinto()
{
	PosicaoInicial_[0] = 0;
	PosicaoInicial_[1] = 0;	
	Linha_ = 0;
	Coluna_ = 0;
	Tamanho_ = 0;

}

void labirinto::InicializaLabirinto()
{
	int Colunas, Linhas;
    int i, j;
	FILE *input = fopen ("C:\Users\Ana\Desktop\Labirinto\Debug\labirinto.txt", "r");

    if(input == NULL){
        printf("****************************************\n");
        printf("*** NAO FOI POSSIVEL ABRIR O ARQUIVO *** \n");
        printf("****************************************\n");
        exit(1);
    }

    do{
        fscanf(input, "%d %d", Linhas, Colunas);
		Linha_ = Linhas;
		Coluna_ = Colunas;
        Tamanho_ = Linha_*Coluna_;

		Labirinto_ = new char* [Linha_];
		for(i =0 ; i<=Linha_ ; i++) 
			Labirinto_[i] = new char[Coluna_];


		for (i=0; i<Linha_; i++)
			for(j=0; j<Coluna_; j++)
				fscanf(input, "%c", Labirinto_[i][j]);
        

    }while(!feof(input));

    fclose(input);
  
}

void labirinto::RemoveLabirinto()
{
	int i;
    
    for( i=0 ; i<Linha_ ; i++ )   
		free(Labirinto_[i]);
	free(Labirinto_);

}

int labirinto::VerificaPosicao(int lin, int col)
{
	char Caractere;
	Caractere = Labirinto_[lin][col];

	 switch (Caractere) {
		case '#': // parede
            return 0;
            break;
        case 'x': // caminho valido
            return 1;
            break;
        case 's': // se for a saida
            return 2;
            break;
        default:
            printf("O Labirinto possui caracteres invalidos!\n");
            return 4;
            break;
    }
}

void labirinto::EncontraInicio()	
{
    int i,j;

    for (i=0; i<Linha_; i++)
		for (j=0; j<Coluna_; j++)
            if (Labirinto_[i][j] == 'e'){
                PosicaoInicial_[0] = i;
				PosicaoInicial_[1] = j;
				break;
            }
			PosicaoAtual_[0] = PosicaoInicial_[0];
			PosicaoAtual_[1] = PosicaoInicial_[1];

}

void labirinto::Caminha(int linha, int coluna, char Dir)
{
	Labirinto_[linha][coluna] = '-';
	if(Dir == 'D') PosicaoAtual_[1]++;
	else if(Dir == 'E') PosicaoAtual_[1]--;
	else if(Dir == 'C') PosicaoAtual_[0]--;
	else if(Dir == 'B') PosicaoAtual_[0]++;
}


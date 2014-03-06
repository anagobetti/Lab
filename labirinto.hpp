#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#ifndef LABIRINTO_HPP
#define LABIRINTO_HPP

#include <iostream>

using namespace std;

class labirinto 
{
public:
	labirinto();
	void InicializaLabirinto();
	void RemoveLabirinto();
	int VerificaPosicao(int x, int y);
	void EncontraInicio();
	void Caminha(int linha, int coluna, char Dir);
	int PosicaoAtual_[2];
	
private:
	int PosicaoInicial_[2];
	int Linha_;
	int Coluna_;
	int Tamanho_;
	char** Labirinto_;
};



#endif

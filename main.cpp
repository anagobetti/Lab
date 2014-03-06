#include "labirinto.hpp"
#include <iostream>
#include <thread>
#include <vector>


labirinto Lab;
bool achou = false;
std::vector<std::thread> threads;

void AchaSaida(int linha, int coluna)
{

	int L, C;
	L = linha;
	C = coluna;
	int caminho = 0;
	char Direcao = 'd';

	while (!achou)
	{

		// testa direita
		if (Lab.VerificaPosicao(L, C+1) == 1)
		{
			caminho++;
			Direcao = 'D';
			if (caminho == 1)
			{
				Lab.Caminha(L, C+1, Direcao);

			}else threads.push_back(std::thread(AchaSaida, L, C+1));
		} else if(Lab.VerificaPosicao(L, C+1) == 2) achou = true; 

		// testa esquerda 
		if (Lab.VerificaPosicao(L, C-1) == 1)
		{
			caminho++;
			Direcao = 'E';
			if (caminho == 1)
			{
				Lab.Caminha(L, C-1, Direcao);
			
			}else threads.push_back(std::thread(AchaSaida, L, C-1));
		} if (Lab.VerificaPosicao(L, C-1) == 2) achou = true;
		
		// testa cima
		if (Lab.VerificaPosicao(L-1, C) == 1)
		{ 
			caminho++;
			Direcao = 'C';
			if (caminho == 1)
			{
				Lab.Caminha(L-1, C, Direcao);
			}else threads.push_back(std::thread(AchaSaida, L-1, C));
		} if (Lab.VerificaPosicao(L-1, C) == 2) achou = true;
		

		 // testa baixo
		if (Lab.VerificaPosicao(L+1, C) == 1)
		{
			caminho++;
			Direcao = 'B';
			if (caminho == 1)
			{
				Lab.Caminha(L+1, C, Direcao);
			}else threads.push_back(std::thread(AchaSaida, L+1, C));
		}if (Lab.VerificaPosicao(L+1, C) == 2) achou = true;
		
		caminho = 0;
		L = Lab.PosicaoAtual_[0];
		C = Lab.PosicaoAtual_[1];

	}
}


int main()
{
	Lab.InicializaLabirinto();
	Lab.EncontraInicio();
	threads.push_back(std::thread(AchaSaida, Lab.PosicaoAtual_[0],Lab.PosicaoAtual_[1]));

	system("PAUSE");
	return 0;
}

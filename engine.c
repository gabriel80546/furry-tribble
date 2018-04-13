#include <stdio.h>
#include <stdlib.h>
#include "objetos.c"

int main()
{
	Fen fen;
	newFen(&fen,"rnbqkbnr/pp1ppppp/8/2p5/4P3/8/PPPP1PPP/RNBQKBNR w KQkq c6 0 2");
	fen.show(fen);
	Posicao teste;
	newPosicao(&teste);
	teste.fen = fen;
	teste.show120(teste);
	teste.show64(teste);
	teste.fenToPosicao(&teste,fen);
	//teste.fen.show(teste.fen);

	return 0;
}

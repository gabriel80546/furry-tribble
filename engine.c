#include <stdio.h>
#include <stdlib.h>
#include "objetos.c"

int main()
{
	Cor cor;
	newCor(&cor);
	Fen fen;
	newFen(&fen,"rnbqkbnr/pp1ppppp/8/2p5/4P3/8/PPPP1PPP/RNBQKBNR w KQkq c6 0 2");

	Posicao posicao;
	newPosicao(&posicao);
	posicao.fen = fen;
	posicao.fenToPosicao(&posicao,fen);
	posicao.show64(posicao);
	posicao.show120(posicao);
	printf("%sfen:%s\n",cor.amarelo.array,cor.normal.array);
	posicao.fen.show(posicao.fen);
	printf("%sMembros da estrutura posicao:%s\n",cor.amarelo.array,cor.normal.array);
	printf("posicao.ladoMover = '%c'\n",posicao.ladoMover);
	printf("posicao.halfMoveCounter = %i\n",posicao.halfMoveCounter);
	printf("posicao.fullMove = %i\n",posicao.fullMove);
	printf("posicao.enPassant = %i\n",posicao.enPassant);
	printf("posicao.roque.grandeBranco = %i\n",posicao.roque.grandeBranco);
	printf("posicao.roque.pequenoBranco = %i\n",posicao.roque.pequenoBranco);
	printf("posicao.roque.grandeBranco = %i\n",posicao.roque.grandePreto);
	printf("posicao.roque.grandePreto = %i\n",posicao.roque.pequenoPreto);
	return 0;
}
typedef struct Posicao2
{
	int board120[120];
	int board64[64];
	Fen fen;
	char ladoMover;
	int halfMoveCounter;
	int fullMove;
	int enPassant;
	Roque roque;
	void (*fenToPosicao)(struct Posicao*, struct Fen);
	void (*zerarPosicao)(struct Posicao*);
	void (*show120)(struct Posicao);
	void (*show64)(struct Posicao);

}Posicao2;

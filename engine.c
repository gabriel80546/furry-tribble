#include <stdio.h>
#include <stdlib.h>
#include "objetos.c"

int main()
{

	int i;
	String debugMsg;
	newString(&debugMsg,"strutura");
	for(i=0;i<2;i++)
	{
		Cor cor;
		newCor(&cor);
		Fen fen;
		if(i==0)
		{
			newFen(&fen,"rnbqkbnr/pp1ppppp/8/2p5/4P3/8/PPPP1PPP/RNBQKBNR w KQkq c6 0 2");
		}
		else if(i==1)
		{
			newFen(&fen,"4k3/8/8/8/8/8/4P3/4K3 w - - 5 39");
		}
		Posicao posicao;
		newPosicao(&posicao);
		posicao.fen = fen;
		posicao.fenToPosicao(&posicao,fen);

		String ifDebug;
		newString(&ifDebug,"strutura");
		if(debugMsg.equals(debugMsg,ifDebug))
		{

			posicao.show64(posicao);
			posicao.show120(posicao);
			printf("%sfen:%s\n",cor.amarelo.array,cor.normal.array);
			posicao.fen.show(posicao.fen);
			printf("%sMembros da estrutura posicao:%s\n",cor.amarelo.array,cor.normal.array);

			printf("%s\"%s\"%s\n",cor.preto.array,posicao.fen.string.array,cor.normal.array);
			printf("posicao.ladoMover = '%c'\n",posicao.ladoMover);

			printf("posicao.halfMoveCounter = %i\n",posicao.halfMoveCounter);
			printf("posicao.fullMove = %i\n",posicao.fullMove);

			printf("posicao.enPassant = %i\n",posicao.enPassant);

			printf("posicao.roque.grandeBranco = %i\n",posicao.roque.grandeBranco);
			printf("posicao.roque.pequenoBranco = %i\n",posicao.roque.pequenoBranco);
			printf("posicao.roque.grandeBranco = %i\n",posicao.roque.grandePreto);
			printf("posicao.roque.grandePreto = %i\n",posicao.roque.pequenoPreto);

		}
	}
	return 0;
}

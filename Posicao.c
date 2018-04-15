/*YCM*/#include "Fen.c"
/*YCM*/#include "Cores.c"
/*YCM*/#include "Erros.c"
/*YCM*/#include <stdlib.h>
typedef struct Roque
{
	int pequenoBranco;
	int pequenoPreto;
	int grandeBranco;
	int grandePreto;
}Roque;
typedef struct Posicao
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

}Posicao;

void PosicaoFenToPosicao(Posicao* posicao, Fen fen)
{
	int i=0,j;
	int validar;
	int casa=0;
	char* array = fen.string.array;
	char cursor = *(array + i);
	Cor cor;
	newCor(&cor);
	Erro erro;
	newErro(&erro);

	while(cursor != ' ')
	{
		if(cursor == '/')
		{i++;}
		else if(cursor >= '1' && cursor <='8')
		{
			casa += cursor-'0';
			i++;
		}
		else
		{
			posicao->board64[casa] = cursor;
			casa++;
			i++;
		}
		cursor = *(array + i);
	}
	i++;
	cursor = *(array + i);
	if(cursor == 'w')
	{
		posicao->ladoMover = *(array + i);
	}
	else if(cursor == 'b')
	{
		posicao->ladoMover = *(array + i);
	}
	else
	{
		fprintf(stderr,"%sFEN Invalido%s\ncausa: caracter que representa lado que vai Mover = '%c'\nem Posicao.c:PosicaoFenToPosicao\nID %i\n",
				cor.vermelho.array,cor.normal.array,cursor,erro.FenLadoMover);
		exit(erro.FenLadoMover);
	}



	posicao->roque.grandeBranco = 0;
	posicao->roque.grandePreto = 0;
	posicao->roque.pequenoBranco = 0;
	posicao->roque.pequenoPreto = 0;

	i++;
	i++;
	cursor = *(array + i);
	while(cursor != ' ')
	{
		printf("cursor = %c\n",cursor);
		if(cursor == 'K')
		{
			posicao->roque.pequenoBranco = 1;
		}
		else if(cursor == 'Q')
		{
			posicao->roque.grandeBranco = 1;
		}
		else if(cursor == 'k')
		{
			posicao->roque.pequenoPreto = 1;
		}
		else if(cursor == 'q')
		{
			posicao->roque.grandePreto = 1;
		}
		else if(cursor != '-')
		{
			fprintf(stderr,"%sFEN Invalido%s\ncausa: caracter que representa direito de rocar = '%c'\nem Posicao.c:PosicaoFenToPosicao\nID %i\n",
					cor.vermelho.array,cor.normal.array,cursor,erro.FenDireitoRocar);
			exit(erro.FenDireitoRocar);
		}
		i++;
		cursor = *(array + i);
	}

	i++;
	cursor = *(array + i);

	while(cursor != ' ')
	{
		if(cursor >= 'a' && cursor <= 'h')
		{
			posicao->enPassant = 10 * (cursor - 'a' + 1);
		}
		else if(cursor == '3')
		{
			posicao->enPassant += 3;
		}
		else if(cursor == '6')
		{
			posicao->enPassant += 6;
		}
		else if(cursor != '-')
		{
			fprintf(stderr,"%sFEN Invalido%s\ncausa: caracter que representa En Passant = '%c'\nem Posicao.c:PosicaoFenToPosicao\nID %i\n",
					cor.vermelho.array,cor.normal.array,cursor,erro.FenEnPassant);
			exit(erro.FenEnPassant);
		}
		i++;
		cursor = *(array + i);
		printf("OI cursor = %c\n",cursor);
	}

	i++;
	cursor = *(array + i);
	printf("Suma cursor = %c\n",cursor);
	i++;
	cursor = *(array + i);
	printf("Suma cursor = %c\n",cursor);
	i++;
	cursor = *(array + i);
	printf("Suma cursor = %c\n",cursor);

	return;
}
void  PosicaoShow120(Posicao posicao)
{
	Cor cor;
	newCor(&cor);
	printf("%sPosicao120:%s\n",cor.amarelo.array,cor.normal.array);
	int i=0;
	int j,k;
	for(k=0;k<12;k++)
	{
		for(j=0;j<10;j++)
		{
			printf("%.2u ",posicao.board120[i]);
			i++;
		}
		printf("\n");
	}
}

void  PosicaoShow64(Posicao posicao)
{
	Cor cor;
	newCor(&cor);
	printf("%sPosicao64:%s\n",cor.amarelo.array,cor.normal.array);
	int i=0;
	int j,k;
	for(k=0;k<8;k++)
	{
		for(j=0;j<8;j++)
		{
			printf("%c ",posicao.board64[i]);
			i++;
		}
		printf("\n");
	}
}

void PosicaoZerarPosicao(Posicao* posicao)
{
	int i;
	int j;
	for(i=0;i<24;i++)
	{posicao->board120[i]=42;}

	for(i=(119-12-11);i<120;i++)
	{posicao->board120[i]=42;}

	for(i=3;i<11;i++)
	{
		posicao->board120[i*10] = 42;
		posicao->board120[i*10 - 1] = 42;
		for(j=2;j<10;j++)
		{
			posicao->board120[(i*10) - j] = 0;
		}
	}
	return;
}


void newPosicao(Posicao* posicao)
{
	int i;

	newFen2(&posicao->fen);
	posicao->show120 = &PosicaoShow120;
	posicao->show64 = &PosicaoShow64;
	posicao->fenToPosicao = &PosicaoFenToPosicao;
	posicao->zerarPosicao = &PosicaoZerarPosicao;
	posicao->zerarPosicao(posicao);
	for(i=0;i<64;i++)
	{posicao->board64[i]='.';}

	return;
}

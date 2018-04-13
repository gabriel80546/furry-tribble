/*YCM*/#include "Fen.c"
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
	int i=0;
	int casa=0;
	char* array = fen.string.array;
	char cursor = *(array + i);

	while(cursor != ' ')
	{
		//printf("%i = %c\n",i,cursor);
		if(cursor == '/')
		{
			i++;
		}
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
	posicao->ladoMover = *(array + i);
	cursor = *(array + i);
	printf("%i = %c\n",i,cursor);
	i++;
	cursor = *(array + i);
	printf("%i = %c\n",i,cursor);
	i++;
	cursor = *(array + i);
	printf("%i = %c\n",i,cursor);
	i++;
	cursor = *(array + i);
	printf("%i = %c\n",i,cursor);
	i++;
	cursor = *(array + i);
	printf("%i = %c\n",i,cursor);
	i++;
	cursor = *(array + i);
	printf("%i = %c\n",i,cursor);
	i++;
	cursor = *(array + i);
	printf("%i = %c\n",i,cursor);


	return;
}
void  PosicaoShow120(Posicao posicao)
{
	printf("\033[1;33mPosicao120:\033[0m\n");
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
	printf("\033[1;33mPosicao64:\033[0m\n");
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

	newFen2(&(*posicao).fen);
	posicao->show120 = &PosicaoShow120;
	posicao->show64 = &PosicaoShow64;
	posicao->fenToPosicao = &PosicaoFenToPosicao;
	posicao->zerarPosicao = &PosicaoZerarPosicao;
	posicao->zerarPosicao(posicao);
	for(i=0;i<80;i++)
	{posicao->board64[i]='.';}

	return;
}

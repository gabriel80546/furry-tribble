/*YCM*/#include "String.c"
/*YCM*/#include <stdio.h>

typedef struct Fen
{
	String string;
	void (*show) (struct Fen);

}Fen;

void FenShow(Fen fen)
{
	int i = 0;
	int j;
	char* array;
	char cursor;

	array = fen.string.array;
	while(fen.string.size > i)
	{
		cursor = *(array+i);
		if(cursor == '/')
		{
			printf("\n");
			i++;
			cursor = *(array+i);
		}
		else if(cursor >= '0' && cursor <= '9')
		{
			for(j=0; j< (cursor-'0') ;j++)
			{printf(". ");}
			i++;
			cursor = *(array+i);
		}
		else if(cursor == ' ')
		{break;}
		else
		{
			printf("%c ",cursor);
			i++;
		}
	}
	printf("\n");
	return;
}

void newFen(Fen* fen,char* stringPosicao)
{
	newString(&fen->string,stringPosicao);
	fen->show = &FenShow;
	return;
}

void newFen2(Fen* fen)
{
	newString(&fen->string,"");
	fen->show = &FenShow;
	return;
}

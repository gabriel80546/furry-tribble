/*YCM*/#include "String.c"
typedef struct Cor
{
	String normal;
	String azul;
	String vermelho;
	String amarelo;
	String verde;
	String preto;
}Cor;

void newCor(Cor* cor)
{
	newString(&cor->normal,"\033[0m");
	newString(&cor->preto,"\033[1;30m");
	newString(&cor->vermelho,"\033[1;31m");
	newString(&cor->verde,"\033[1;32m");
	newString(&cor->amarelo,"\033[1;33m");
	newString(&cor->azul,"\033[1;34m");
}

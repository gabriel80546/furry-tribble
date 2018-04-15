/*YCM*/#include "String.c"
/*YCM*/#include "Cores.c"
typedef struct Erro
{
	int FenLadoMover;
	int FenDireitoRocar;
	int FenEnPassant;
}Erro;
void newErro(Erro* erro)
{
	erro->FenLadoMover = 1;
	erro->FenDireitoRocar = 2;
	erro->FenEnPassant = 3;
}

echo -e "\033[1;32m./compile.sh\033[0m"

echo -e "\033[7mrm ../.*.swp\033[0m"
rm ../.*.swp
echo -e "\033[7mmkdir temp\033[0m"
mkdir temp
echo -e "\033[7mcp ../*.c temp/\033[0m"
cp ../*.c temp/
echo -e '\033[7mcat ../Fen.c | sed "s|/\*YCM\*/|//|" > temp/Fen.c\033[0m'
# TODO GENERALIZAR
cat ../Fen.c | sed "s|/\*YCM\*/|//|" > temp/Fen.c
echo -e '\033[7mcat ../Fen.c | sed "s|/\*YCM\*/|//|" > temp/Fen.c\033[0m'
cat ../Posicao.c | sed "s|/\*YCM\*/|//|" > temp/Posicao.c
echo -e "\033[7mgcc -Og -g -o ../engine ../engine.c\033[0m"
echo -e "\$? = $?"
gcc -Og -g -o  ../engine ./temp/engine.c 2>err
if [ $? -eq 0 -a ! -s err ]
then
	echo -e "\033[1;32mCompilaçao deu certo\033[0m"
else
	cat err
	echo -e "\033[1;31mCompilação deu merda\033[0m"
fi
echo -e "\033[7mgcc -O1 -g -o engineO1 ../engine.c\033[0m"
gcc -O1 -g -o  z/engineO1 ./temp/engine.c 2>err
if [ $? -eq 0 -a ! -s err ]
then
	echo -e "\033[1;32mCompilaçao deu certo\033[0m"
else
	cat err
	echo -e "\033[1;31mCompilação deu merda\033[0m"
fi
echo -e "\033[7mgcc -O2 -g -o engineO2 ../engine.c\033[0m"
gcc -O2 -g -o  z/engineO2 ./temp/engine.c 2>err
if [ $? -eq 0 -a ! -s err ]
then
	echo -e "\033[1;32mCompilaçao deu certo\033[0m"
else
	cat err
	echo -e "\033[1;31mCompilação deu merda\033[0m"
fi
echo -e "\033[7mgcc -O3 -g -o engineO3 ../engine.c\033[0m"
gcc -O3 -g -o  z/engineO3 ./temp/engine.c 2>err
if [ $? -eq 0 -a ! -s err ]
then
	echo -e "\033[1;32mCompilaçao deu certo\033[0m"
else
	cat err
	echo -e "\033[1;31mCompilação deu merda\033[0m"
fi
echo -e "\033[7mgcc -O0 -g -o engineO0 ../engine.c\033[0m"
gcc -O0 -g -o  z/engineO0 ./temp/engine.c 2>err
if [ $? -eq 0 -a ! -s err ]
then
	echo -e "\033[1;32mCompilaçao deu certo\033[0m"
else
	cat err
	echo -e "\033[1;31mCompilação deu merda\033[0m"
fi
echo -e "\033[7mgcc -Os -g -o engineOs ../engine.c\033[0m"
gcc -Os -g -o  z/engineOs ./temp/engine.c 2>err
if [ $? -eq 0 -a ! -s err ]
then
	echo -e "\033[1;32mCompilaçao deu certo\033[0m"
else
	cat err
	echo -e "\033[1;31mCompilação deu merda\033[0m"
fi
echo -e "\033[7mgcc -Ofast -g -o engineOfast ../engine.c\033[0m"
gcc -Ofast -g -o  z/engineOfast ./temp/engine.c 2>err
if [ $? -eq 0 -a ! -s err ]
then
	echo -e "\033[1;32mCompilaçao deu certo\033[0m"
else
	cat err
	echo -e "\033[1;31mCompilação deu merda\033[0m"
fi

echo -e "\033[7mrm -r temp\033[0m"
rm -r temp

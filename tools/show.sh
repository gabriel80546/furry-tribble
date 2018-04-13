while [ true ]
do
	clear
	echo -e "\033[1;32mshow.sh\033[0m"
	echo -e "\033[1;32mArquivos .h\033[0m"
	tree .. -P '*.h'
	echo -e "\033[1;32mArquivos .c\033[0m"
	tree .. -P '*.c'
	echo -e "\033[1;32mArquivos .sh\033[0m"
	tree .. -P '*.sh'
	sleep 0.5
done

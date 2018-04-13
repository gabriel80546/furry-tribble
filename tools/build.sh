echo -e "\033[1;32m./build.sh\033[0m"
echo -e "\033[7mcd build\033[0m"
cd ../build
echo -e "\033[7mcmake ..\033[0m"
cmake ..
echo -e "\033[7mrm ../compile_commands.json\033[0m"
rm ../compile_commands.json
echo -e "\033[7mcp compile_commands.json ..\033[0m"
cp compile_commands.json ..

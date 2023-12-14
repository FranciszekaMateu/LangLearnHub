#!/bin/bash

# Colores
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# Compila tu programa si es necesario
# g++ -o myprogram myprogram.cpp

# Ejecuta tu programa con la entrada generada y guarda la salida
valgrind ../main < input1.txt > actual_output.txt

# Compara la salida actual con la salida esperada
DIFF=$(diff actual_output.txt expectedOutput1.txt)

if [ "$DIFF" != "" ]
then
    echo -e "${RED}Test Fallido!${NC} Revisa actual_output.txt para más detalles."
    echo "$DIFF"
else
    echo -e "${GREEN}¡Test Exitoso!${NC}"
fi


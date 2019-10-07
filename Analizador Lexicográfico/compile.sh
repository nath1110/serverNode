rm dist/main
g++ -c scanner.cpp lexico.cpp auxiliares.cpp pl0.cpp
g++ scanner.o lexico.o auxiliares.o pl0.o -o main
rm scanner.o lexico.o auxiliares.o pl0.o
mv main dist/main
./dist/main

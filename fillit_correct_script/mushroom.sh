#!/bin/bash

NAME="corob"
echo "\033[31mNORME\033[0m"
read $VAR

norminette ../$NAME
echo "\033[31mNORME SUITE\033[0m"
read $VAR

find ../$NAME -name '*.c' -exec cat {} \; | grep "\+\n"
find ../$NAME -name '*.c' -exec cat {} \; | grep "\*\n"
find ../$NAME -name '*.c' -exec cat {} \; | grep "\-\n"
find ../$NAME -name '*.c' -exec cat {} \; | grep "\ \/\n"
find ../$NAME -name '*.c' -exec cat {} \; | grep "\&\n"
find ../$NAME -name '*.c' -exec cat {} \; | grep "\|\n"
find ../$NAME -name '*.c' -exec cat {} \; | grep "\%\n"
echo "\033[31mAUTEUR\033[0m"
read $VAR

cat -e ../$NAME/auteur
echo "\033[31mMAKE\033[0m"
read $VAR

make re -C ../$NAME
make clean -C ../$NAME
echo "\033[31mFONCTIONS\033[0m"
read $VAR

nm -u ../$NAME/fillit
echo "\033[31mMALLOC\033[0m"
read $VAR

find ../$NAME -name '*.c' -exec cat {} \; | grep "join"
find ../$NAME -name '*.c' -exec cat {} \; | grep "strnew"
find ../$NAME -name '*.c' -exec cat {} \; | grep "strdup"
find ../$NAME -name '*.c' -exec cat {} \; | grep "malloc"
echo "\033[31mINCLUDES\033[0m"
read $VAR

find ../$NAME -name '*.*' -exec cat {} \; | grep "include"
echo "\033[31mLOGIN\033[0m"
read $VAR

find ../$NAME -name '*.*' -exec cat {} \; | grep "by"
echo "\033[31mTEST ERREUR FACILE\033[0m"
read $VAR

valgrind ./../$NAME/fillit
valgrind ./../$NAME/fillit file/error1
valgrind ./../$NAME/fillit /dev/null
echo "\033[31mSUITE\033[0m"
read $VAR

valgrind ./../$NAME/fillit file/error2
valgrind ./../$NAME/fillit file/error3
valgrind ./../$NAME/fillit file/error4
valgrind ./../$NAME/fillit file/error5

echo "\033[31mSUITE\033[0m"
read $VAR

valgrind ./../$NAME/fillit file/error6
valgrind ./../$NAME/fillit file/error7
valgrind ./../$NAME/fillit file/error8
valgrind ./../$NAME/fillit file/error9

echo "\033[31mTEST ERREUR MOYEN\033[0m"
read $VAR

valgrind ./../$NAME/fillit file
echo "\033[31mTEST ERREUR DIFFICILE\033[0m"
read $VAR

echo "\033[31mTEST FACILE\033[0m"
read $VAR

valgrind ./../$NAME/fillit file/test1
valgrind ./../$NAME/fillit file/test2
valgrind ./../$NAME/fillit file/test3
valgrind ./../$NAME/fillit file/test5
echo "\033[31mTEST MEDIUM\033[0m"
read $VAR

valgrind ./../$NAME/fillit file/test4
valgrind ./../$NAME/fillit file/test6

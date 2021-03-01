SRC= SRC/test_case.c\
	SRC/factorial.c\
	SRC/flip.c\
	SRC/ispalindrome.c\
	SRC/isprime.c\
	SRC/reset.c\
	SRC/set.c\
	SRC/strcmp.c\
	SRC/strlen.c\
	SRC/vsum.c

INC= -Iinclude

SRCs=./strcmp.o\
    ./strlen.o

SRCb=./flip.o\
    ./reset.o\
    ./set.o\

SRCu=./factorial.o\
    ./ispalindrome.o\
    ./isprime.o\
    ./vsum.o

build: $(SRC)
	gcc $(INC) $(SRC) -c 
buildstr:
	ar rc libmystr.a $(SRCs)
buildutils:
	ar rc libmysutils.a $(SRCu)
buildmask:
	ar rc libmask.a $(SRCb)
gens1:
	gcc -L. test_case.o -o s1.out -lmask -lmystr -lmysutils
builddutils:
	gcc -shared -o libmysutils.so $(SRCu)
builddstr:
	gcc -shared -o libmask.so ${SRCs}
builddmask:
	gcc -shared -o libmask.so ${SRCb}
gend1:
	gcc -L. test_case.o -o d1.out -lmask -lmystr -lmysutils	



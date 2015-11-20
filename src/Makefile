IDIR=../include
CC=clang++
CFLAGS= -I$(IDIR) -fopenmp -std=c++11

ODIR=obj
LDIR=../lib

LIBS=-larmadillo -lblas

_DEPS=randomInitialize.hpp sigmoid.hpp costFunction.hpp printMat.hpp fminConjGrad.hpp
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ=randomInitialize.o sigmoid.o costFunction.o printMat.o fminConjGrad.o train.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

nnmake: $(OBJ)
	clang++ -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 

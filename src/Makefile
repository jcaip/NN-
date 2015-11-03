IDIR=../include
CC=clang++
CFLAGS= -I$(IDIR) -fopenmp

ODIR=obj
LDIR=../lib

LIBS=-lm

_DEPS=randomInitialize.hpp sigmoid.hpp costFunction.hpp printMat.hpp
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ=randomInitialize.o sigmoid.o costFunction.o printMat.o train.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

nnmake: $(OBJ)
	clang++ -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 

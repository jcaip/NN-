IDIR=../include
CC=clang++
CFLAGS= -I$(IDIR)

ODIR=obj
LDIR=../lib

LIBS=-lm

_DEPS=randomInitialize.hpp sigmoid.hpp costFunction.hpp
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ=randomInitialize.o train.o sigmoid.o costFunction.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

nnmake: $(OBJ)
	clang++ -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 

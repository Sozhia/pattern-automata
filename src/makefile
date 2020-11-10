CC=g++
CFLAGS=-I.
DEPS = ./automata.h
OBJ = ./pattern_search.o

%.o:  %.cc $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

pattern_search: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -rf ./*o pattern_search 
exec=th.out
sources=$(wildcard src/*.c)
objects=$(sources:.c=.o)
flags=-g -Wall

$(exec): $(objects)
	gcc $(objects) $(flags) -o $(exec)

%.o: %.c include/%.h
	gcc -c $(sources) $(flags) $< -o $@

clean:
	-rm src/*.o
	-rm *.out
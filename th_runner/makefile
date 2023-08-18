exec=th.out
sources=$(wildcard src/*.c)
objects=$(sources:.c=.o)
flags=-g -Wall

$(exec): $(objects)
	gcc $(objects) $(flags) -o bin/$(exec)

%.o: %.c include/%.h
	gcc -c $(sources) $(flags) $< -o $@

run:
	./bin/$(exec)

clean:
	-rm src/*.o
	-rm bin/*.out
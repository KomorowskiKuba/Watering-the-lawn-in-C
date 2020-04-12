podlewanie: main3.o kolka.o rysowanie.o okrag.o krawedzie.o rogi.o
	$(CC) -o podlewanie main3.o kolka.o rysowanie.o okrag.o krawedzie.o rogi.o -lm

.PHONY: clean

clean:
	-rm *.o podlewanie



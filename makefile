signals: main.c
	gcc main.c -o signals

run: signals
	./signals

clean:
	rm *~

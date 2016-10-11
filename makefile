linktest: LinkedList.c
	gcc LinkedList.c -o linktest

clean: 
	rm *~

run: linktest
	./linktest
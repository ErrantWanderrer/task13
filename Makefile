CC=gcc			#переменная (макрос) с именем компилятора
CFLAGS=-c -std=c99	#переменная с перечислением флагов
OUTPUT=vector		#имя исполняемого файла

goal: main.o vector.o
	$(CC) main.o vector.o -o $(OUTPUT)
	
main.o: main.c
	$(CC) main.c $(CFLAGS)
	
vector.o: vector.c
	$(CC) vector.c $(CFLAGS)

clean:
	rm -rf *.o $(OUTPUT)

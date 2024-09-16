TARGET = projeto_labprog
CC = gcc
CFLAGS = -Wall
SRCS = main.c calculo_investimento.c gerenciamento_investimento.c
LIBS = -lm

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET).out $(SRCS) $(LIBS)
clean:
	rm -f *.o projeto_labprog.out

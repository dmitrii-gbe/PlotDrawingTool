compiler := gcc
compiler_flags := -Werror -Wextra -Wall -std=c11
root_source_dir := .
binaries_directory := build

all: graph

expression_processing.o: expression_processing.c
	@$(compiler) -c $(root_source_dir)/expression_processing.c ${compiler_flags}

draw.o: draw.c
	@$(compiler) -c draw.c ${compiler_flags}

evaluation.o: evaluation.c
	@$(compiler) -c evaluation.c ${compiler_flags}

stack.o: stack.c
	@$(compiler) -c stack.c ${compiler_flags}

graph.o: graph.c
	@$(compiler) -c graph.c ${compiler_flags}

graph: expression_processing.o draw.o evaluation.o stack.o graph.o
	mkdir -p $(binaries_directory)
	@$(compiler) -o $(binaries_directory)/graph expression_processing.o draw.o evaluation.o stack.o graph.o

clean:
	@rm *.o
	@rm ../build/*

rebuild:
	@make clean
	@make all

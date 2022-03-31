run:
	@clear
	@echo "compilling..."
	@cc -c huffman.c && cc -c linkedList.c
	@cc -o huffman huffman.o linkedList.o
	@clear
	@echo "done compilling; executing..."
	@./huffman
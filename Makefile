run:
	@echo "compilling..."
	@cc -c huffman.c && cc -c linkedList.c
	@cc -o huffman huffman.o linkedList.o
	@echo "done compilling; executing..."
	@./huffman
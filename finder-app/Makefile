
ifeq ($(CROSS_COMPILE), aarch64-none-linux-gnu-)
	CC=/home/izyakantorovich/arm-gnu-toolchain-13.3.rel1-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-gcc
else
	CC=gcc
endif
	
writer: writer.c
	${CC} writer.c -o writer
	
.PHONY: clean
clean:
	@rm writer

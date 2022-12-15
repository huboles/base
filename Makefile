SHELL = /bin/bash
PROG = printbin

debug:
	gcc *.c *.h -Wall -lm -g -o printbin

printbin:
	gcc *.c *.h -Wall -lm -o printbin

install:
	gcc *.c *.h -Wall -lm -o /home/huck/.local/bin/printbin

clean: 
	rm /home/huck/.local/bin/printbin

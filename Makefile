SHELL = /bin/bash
PROG = base
PREFIX = /usr
DESTDIR = /bin

CFILE = main.c function.c
HEADER = base.h

header: ${HEADER}
	gcc ${CFILE} ${HEADER} -lm -Wall -o ${PROG}

install: ${CFILE} ${HEADER}
	gcc ${CFILE} ${HEADER} -lm -Wall -o ${PREFIX}${DESTDIR}/${PROG}

debug: ${CFILE}
	gcc ${CFILE} -lm -Wall -g -o ${PROG}

clean:
	rm ${PREFIX}${DESTDIR}/${PROG}

BIN = ${DESTDIR}/usr/sbin

stealth:
	./build

clean:
	rm -rf libstealth.a stealth */o

install: stealth
	install stealth ${BIN}

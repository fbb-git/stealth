BIN = ${DESTDIR}/usr/sbin

all: stealth smanpage smanual

stealth:
	./build

smanual:
	./buildmanual

smanpage:
	./buildmanpage

clean: cleanstealth cleanlib cleanmanpage cleanmanual

cleanlib:
	rm -f libstealth.a

cleanstealth:
	rm -f stealth

cleanmanpage:
	rm -f manpage/stealth.1

cleanmanual:
	rm -rf manual/{LaTeX,html,pdf,ps,text}/[a-z]*



install: stealth
	install stealth ${BIN}

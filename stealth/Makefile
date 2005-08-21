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
	echo rm -f libstealth.a

cleanstealth:
	echo rm -f stealth

cleanmanpage:
	echo rm -f manpage/stealth.1

cleanmanual:
	echo rm -rf manual/{LaTeX,html,pdf,ps,text}

install: stealth
	install stealth ${BIN}


SRC = src/
CC = ./gbdk-n/bin/gbdk-n-compile.sh
LL = ./gbdk-n/bin/gbdk-n-link.sh
MR = ./gbdk-n/bin/gbdk-n-make-rom.sh
OBJECTS = $(patsubst %.c,%.rel,$(wildcard src/*.c))
TITLE = test_plateform

$(TITLE).gb: $(OBJECTS)
	$(LL) -o $(SRC)$(TITLE).ihx $^
	$(MR) $(SRC)$(TITLE).ihx $(TITLE).gb

src/%.rel: src/%.c
	$(CC) -o $@ -c $<

run:
	wine bgb64.exe $(TITLE).gb

clean:
	rm -rf src/*.rel
	rm -rf src/*.lst
	rm -rf src/*.sym
	rm -rf src/*.asm

	rm -rf src/$(TITLE)*.ihx
	rm -rf src/$(TITLE)*.map
	rm -rf src/$(TITLE)*.sym
	rm -rf src/$(TITLE)*.noi

	rm -rf $(TITLE)*.gb
	rm -rf temp.lnk

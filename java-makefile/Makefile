# build Java projects
SRC=src
BIN=bin
BUILD=build
JAR=$(BUILD)/`basename $(PWD)`.jar
MANIFEST=$(SRC)/Manifest.txt
JCC=javac
JFLAGS=-g
JARCC=jar
JARFLAGS=cfm

all: $(SRC)/*.java
	$(JCC) $(JFLAGS) $(SRC)/*.java
	if [ -a $(SRC)/*.class ]; then \
		mv $(SRC)/*.class $(BIN); \
		cd $(BIN); \
		$(JARCC) $(JARFLAGS) ../$(JAR) ../$(MANIFEST) .; \
	fi; \

clean: 
	rm -f $(BUILD)/*.jar
	rm -f $(BIN)/*.class

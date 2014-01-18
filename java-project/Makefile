# build Java projects
SRC=src
BIN=bin
BUILD=build
JAR=$(BUILD)/`basename $(PWD)`.jar
MANIFEST=$(SRC)/manifest.txt
JCC=javac
JFLAGS=-g
JARCC=jar
JARFLAGS=cfm

all: $(SRC)/**/*.java
	$(JCC) $(JFLAGS) $(SRC)/**/*.java -d $(BIN)
	cd $(BIN)
	$(JARCC) $(JARFLAGS) $(JAR) $(MANIFEST) .

clean: 
	rm -f $(BUILD)/*.jar
	rm -f $(BIN)/**/*.class

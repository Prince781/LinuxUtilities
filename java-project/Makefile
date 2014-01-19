# build Java projects
SRC=src
BIN=bin
BUILD=build
LIB=lib
JAR=$(BUILD)/`basename $(PWD)`.jar
MANIFEST=$(SRC)/manifest.txt
JCC=javac
JFLAGS=-g
JARCC=jar
JARFLAGS=cfm
JFILES=$(shell find $(SRC) -type f -name '*.java')

all: $(JFILES)
	$(JCC) $(JFLAGS) -extdirs $(LIB)/lwjgl $(JFILES) -d $(BIN)
	@$(JARCC) $(JARFLAGS) $(JAR) $(MANIFEST) $(BIN)/com

clean: 
	@rm -f $(BUILD)/*.jar
	@rm -f $(BIN)/**/*.class

# build Java projects
SRC=src
BIN=bin
LIB=lib
DOC=doc
JAR="`basename \"$(PWD)\"`.jar"
MANIFEST=META-INF/MANIFEST.MF
JCC=javac
LIBJARS:=$(shell find $(LIB) -type f -name '*.jar' | tr '\n' ':')
JFLAGS=-g
JARCC=jar
JARFLAGS=cfm
JFILES=$(shell find $(SRC) -type f -name '*.java')
SUBPACKAGES:=$(shell cd $(SRC) && find . -mindepth 1 -maxdepth 1 -type d && cd ..)
JDOCCC=javadoc
JDOPTS=-d $(DOC) -classpath $(LIBJARS) -sourcepath $(SRC)
ORACLEDOCS=http://docs.oracle.com/javase/8/docs/api/
JDFLAGS=-use -author -link $(ORACLEDOCS)

all: folders $(JFILES)
	$(JCC) -classpath $(LIBJARS) $(JFLAGS) $(JFILES) -d $(BIN)
	$(JARCC) $(JARFLAGS) $(JAR) $(MANIFEST) -C $(BIN) .
	zip -g $(JAR) -r lib_natives
	zipmerge $(JAR) $(shell find $(LIB) -type f -name '*.jar')
	zip -g $(JAR) $(MANIFEST)

folders:
	@if [ ! -d bin ]; then mkdir bin; fi
	@if [ ! -d lib ]; then mkdir lib; fi
	@if [ ! -d doc ]; then mkdir doc; fi

javadoc: $(JFILES)
	$(JDOCCC) $(JDOPTS) $(JDFLAGS) -subpackages com

clean: clean-javadoc
	@rm -f $(JAR)
	@rm -rf $(BIN)/*

clean-javadoc:
	@rm -rf $(DOC)


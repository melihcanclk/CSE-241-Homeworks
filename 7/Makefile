JAVAC=javac
JAVA=java
MAIN=Main
sources = $(wildcard *.java)
classes = $(sources:.java=.class)

all: myProgram

myProgram: $(classes)

%.class: %.java
	$(JAVAC) $<

clean:
	rm -f *.class
	rm -f *.txt


CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_CLASS=NumClass.h
OBJECTS_BASIC= basicClassification.o
OBJECTS_LOOP= advancedClassificationLoop.o
OBJECTS_REC= advancedClassificationRecursion.o
FLAGS= -Wall -g


loops: libclassloops.a
libclassloops.a: $(OBJECTS_LOOP) $(OBJECTS_BASIC)
	$(AR) -rcs libclassloops.a $(OBJECTS_LOOP) $(OBJECTS_BASIC)

recursives: libclassrec.a
libclassrec.a: $(OBJECTS_REC) $(OBJECTS_BASIC)
	$(AR) -rcs libclassrec.a $(OBJECTS_REC) $(OBJECTS_BASIC)

recursived: libclassrec.so
libclassrec.so: $(OBJECTS_REC) $(OBJECTS_BASIC)
	$(CC) -shared -o libclassrec.so $(OBJECTS_REC) $(OBJECTS_BASIC) -lm

loopd: libclassloops.so
libclassloops.so: $(OBJECTS_LOOP) $(OBJECTS_BASIC)
	$(CC) -shared -o libclassloops.so $(OBJECTS_LOOP) $(OBJECTS_BASIC) -lm

mains: $(OBJECTS_MAIN) libclassrec.a
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) libclassrec.a -lm
#  what is the instructions?^^^^ 

maindloop: $(OBJECTS_MAIN) libclassloops.so
	$(CC) $(FLAGS) -o maindloop $(OBJECTS_MAIN) ./libclassloops.so  -lm 

maindrec: $(OBJECTS_MAIN) libclassrec.so 
	$(CC) $(FLAGS) -o maindrec $(OBJECTS_MAIN) -lm -fPIC ./libclassrec.so

all:loops loopd recursived recursives mains maindloop maindrec

clean : 
		rm -f *.o *.a *.so *.exe  mains maindloop maindrec

basicClassification.o: $(OBJECTS_CLASS) basicClassification.c
	$(CC) $(FLAGS) -c basicClassification.c
advancedClassificationLoop.o: $(OBJECTS_CLASS) advancedClassificationLoop.c
	$(CC) $(FLAGS) -c advancedClassificationLoop.c -lm
advancedClassificationRecursion.o: $(OBJECTS_CLASS) advancedClassificationRecursion.c
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c -lm
main.o:$(OBJECTS_CLASS) main.c 
	$(CC) $(FLAGS) -c main.c 

.PHONY: clean all


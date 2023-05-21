MY_SHELLS = my_shells
MY_STORAGE_USE = my_storage_use
MY_USERID = my_userid
TARGET = ${MY_SHELLS} ${MY_STORAGE_USE} ${MY_USERID}

CC = gcc
CFLAGS  = -g -Wall

all: ${TARGET}

${MY_SHELLS}: ${MY_SHELLS}.c
	$(CC) $(CFLAGS) -o $(MY_SHELLS) $(MY_SHELLS).c

${MY_STORAGE_USE}: ${MY_STORAGE_USE}.c
	$(CC) $(CFLAGS) -o $(MY_STORAGE_USE) $(MY_STORAGE_USE).c

${MY_USERID}: ${MY_USERID}.c
	$(CC) $(CFLAGS) -o $(MY_USERID) $(MY_USERID).c


clean:
	-rm -f  $(TARGET) *.dmagit

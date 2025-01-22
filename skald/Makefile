CC=gcc
CFLAGS=-luuid

TARGET = skald
SRC = $(TARGET).c
DB_FILE = SKALDB_BLOCKFILE

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) -o $(TARGET) $(SRC) $(CFLAGS)



# Clean target to remove the executable
clean:
	rm -f $(TARGET)
rmdb:
	rm -rf $(DB_FILE)

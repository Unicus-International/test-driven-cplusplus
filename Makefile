PRODUCT=harness

OFLAGS=

ifeq ($(RELEASE), 1)
	OFLAGS=-Ofast -DRELEASE
else
	OFLAGS=-O0
endif

CC=clang++
CFLAGS=$(OFLAGS) -Wall -Iinc -stdlib=libc++ -std=c++17
LFLAGS=-stdlib=libc++

TDIR=
TODIR=
ODIR=obj
DDIR=obj
BDIR=./bin

SRC_DIR=src

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
HEADERS = $(wildcard $(SRC_DIR)/*.hpp)
_OBJS = $(SOURCES:$(SRC_DIR)/%.cpp=%.o)

_TEST = 
TEST = $(patsubst %,$(TODIR)/%.test,$(_TEST))

OBJ = $(patsubst %,$(ODIR)/%,$(_OBJS))

$(BDIR)/$(PRODUCT): $(ODIR) $(OBJ) $(BDIR)
	$(CC) -o $@ $(OBJ) $(LFLAGS)

$(ODIR):
	mkdir -p $(ODIR)

$(BDIR):
	mkdir -p $(BDIR)

$(ODIR)/%.o: src/%.cpp
	$(CC) -MMD -c -g -std=c++17 -o $@ $< $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(DDIR)/*.d $(ODIR)/*.o $(BDIR)/$(PRODUCT)

-include $(SOURCES:$(SRC_DIR)/%.cpp=$(DEPDIR)/%.P)
-include ${OBJ:.o=.d}

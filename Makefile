# Package info
PACKAGE = mnl
VER = 1.0.0
LINKNAME = lib$(PACKAGE).so
LIBFILE = $(LINKNAME).$(VER)

# Compiler info
CXX = g++
CXXFLAGS = -c -fPIC
INC = include
OBJ = obj
SRC = src
LIB = lib

OBJFILES = $(OBJ)/*.o

# Default install directory
prefix ?= /usr/local

$(LIB)/$(LIBFILE): $(OBJFILES)
	$(CXX) -shared -o $@ $^

install: $(LIB)/$(LIBFILE)
	@echo Installing to $(prefix)/lib
	install -m 0755 $^ $(prefix)/lib
	ln -s $(prefix)/lib/$(LIBFILE) $(prefix)/lib/$(LINKNAME)
	@echo Installing header files to $(prefix)/$(INC)/$(PACKAGE)
	install -d -m 0755 $(prefix)/$(INC)/$(PACKAGE)
	install -m 0644 $(INC)/$(PACKAGE)/*.h $(prefix)/$(INC)/$(PACKAGE)

uninstall:
	@echo Uninstalling from $(prefix)
	rm -f $(prefix)/lib/$(LIBFILE)
	rm -f $(prefix)/lib/$(LINKNAME)
	rm -rf $(prefix)/$(INC)/$(PACKAGE)

$(OBJ)/%.o: $(SRC)/%.cc
	$(CXX) -I$(INC) $(CXXFLAGS) -o $@ $^ 

clean:
	rm -f $(LIB)/* $(OBJ)/*

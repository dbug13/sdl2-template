SDL2CFLAGS := $(shell sdl2-config --cflags)
SDL2LDFLAGS := $(shell sdl2-config --libs)
CXX := g++
CXXFLAGS := -Wall -std=c++20 $(SDL2CFLAGS)
LDLIBS := $(SDL2LDFLAGS) -lSDL2_image
LDFLAGS := 
BUILDDIR := ./build
ASSETDIR := ./assets
ASSETS := $(BUILDDIR)/assets
SRCDIR := ./src
SRCFILES := $(shell find $(SRCDIR)/ -type f -name '*.cpp')
OBJFILES := $(patsubst %.cpp,%.o, $(SRCFILES))
TARGET := $(BUILDDIR)/hello

all: init $(TARGET)

init:
	@mkdir -p $(BUILDDIR)

$(TARGET): $(OBJFILES)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)
	cp -r $(ASSETDIR) $(BUILDDIR)

$(SRCDIR)/**/%.o: $(SRCDIR)/**/%.cpp $(SRCDIR)/**/%.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJFILES) $(TARGET)
	rm -rf $(ASSETS)

run: init $(TARGET)
	$(TARGET)

.PHONY: all clean
PLUGINS = BallController.so MarkerController.so

all: $(PLUGINS)

CNOID_PATH = $(shell which choreonoid)
CNOID_DIR  = $(subst /bin/choreonoid,,$(CNOID_PATH))

CXXFLAGS += -fPIC -DQT_NO_KEYWORDS -DQT_SHARED -I$(CNOID_DIR)/include/choreonoid-1.8 -I/usr/include/eigen3 -std=c++11

$(PLUGINS) : %.so : %.o
	g++ -shared -o $@ $^ -L$(CNOID_DIR)/lib -L/usr/local/lib -lCnoidUtil -lCnoidBase -lCnoidBody

#install: $(PLUGINS)
#	install -s $(PLUGINS) `pkg-config --variable=simplecontroller choreonoid

clean:
	rm -f *.o *.so

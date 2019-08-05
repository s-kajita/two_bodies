PLUGINS = BallController.so MarkerController.so

all: $(PLUGINS)

CNOID_DIR = $(HOME)/openrtp
#CNOID_DIR = $(HOME)/catkin_ws/devel
CXXFLAGS += -fPIC -DQT_NO_KEYWORDS -DQT_SHARED -I$(CNOID_DIR)/include/choreonoid-1.8 -I/usr/include/eigen3 -std=c++11

$(PLUGINS) : %.so : %.o
	g++ -shared -o $@ $^ -L$(CNOID_DIR)/lib -L/usr/local/lib -lCnoidUtil -lCnoidBase -lCnoidBody

#marker_control.so : %.so : %.o
#	g++ -shared -o $@ $^ -L$(CNOID_DIR)/lib -L/usr/local/lib -lCnoidUtil -lCnoidBase -lCnoidBody

#BallController.so : %.so : %.o marker_control.o
#	g++ -shared -o $@ $^ -L$(CNOID_DIR)/lib -L/usr/local/lib -lCnoidUtil -lCnoidBase -lCnoidBody

install: $(PLUGINS)
	install -s $(PLUGINS) `pkg-config --variable=plugindir choreonoid`

clean:
	rm -f *.o *.so

PROJECT_BINARY_NAME = tf-minimal
PROJECT_SOURCES = minimal.cc


all:	$(PROJECT_BINARY_NAME)

$(PROJECT_BINARY_NAME):	$(PROJECT_SOURCES)
	$(CXX) -std=c++11 $(CXXFLAGS) $(PROJECT_SOURCES) -o $(PROJECT_BINARY_NAME) -ltensorflow-lite -lflatbuffers


clean:
	rm -f $(PROJECT_BINARY_NAME)

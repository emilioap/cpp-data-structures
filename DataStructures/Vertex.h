#include <string>

class Vertex {
public:
	Vertex() {
		this->name = "";
	}
	Vertex(std::string name) {
		this->name = name;
	}
	std::string getName() const {
		return name;
	}
private:
	std::string name;
};
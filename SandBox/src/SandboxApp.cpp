#include <Orgeng.h>

class Sandbox : public Orgeng::Application {
public:
	Sandbox() {

	}
	~Sandbox() {

	}
};

Orgeng::Application* Orgeng::CreateApplication() {
	return new Sandbox();
}
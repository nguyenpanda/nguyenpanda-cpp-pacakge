#include <nguyenpanda.h>

int main() {
    nguyenpanda::swan::FourBitColor color;

    std::cout << color[' '] << "Hello world" << color.reset << std::endl;
    std::cout << color['r'] << "Hello world" << color.reset << std::endl;
    std::cout << color['g'] << "Hello world" << color.reset << std::endl;
    std::cout << color['y'] << "Hello world" << color.reset << std::endl;
    std::cout << color['b'] << "Hello world" << color.reset << std::endl;
    std::cout << color['m'] << "Hello world" << color.reset << std::endl;
    std::cout << color['c'] << "Hello world" << color.reset << std::endl;

    std::cout << color[" "] << "Hello world" << color.reset << std::endl;
    std::cout << color["r"] << "Hello world" << color.reset << std::endl;
    std::cout << color["g"] << "Hello world" << color.reset << std::endl;
    std::cout << color["y"] << "Hello world" << color.reset << std::endl;
    std::cout << color["b"] << "Hello world" << color.reset << std::endl;
    std::cout << color["m"] << "Hello world" << color.reset << std::endl;
    std::cout << color["c"] << "Hello world" << color.reset << std::endl;

    std::cout << " ================================= " << std::endl;

    for (int i = 0; i < 1000; ++i) {
        std::cout << i << ". " << color.random() << "Random" << color.reset << std::endl;
    }

    return 0;
}
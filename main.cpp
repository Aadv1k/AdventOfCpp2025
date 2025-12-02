#include <dlfcn.h>
#include <iostream>
#include <fstream>

int main(int argc, char** argv) {
    void (*part_a)(std::string input);
    void (*part_b)(std::string input);

    if (argc < 3) {
        std::cerr << "You need to specify the day, followed by the input file\n";
        return 1; 
    }

    // TODO: add windows support
    std::string day_label(argv[1]);
    day_label += ".so";

    void* handle = dlopen(day_label.c_str(), RTLD_LAZY);

    if (!handle) {
        std::cerr << "Failed to open " << day_label << ": " << dlerror() << "\n";
        return 1;
    }

    std::ifstream input_file(argv[2]);
    if (!input_file) {
        std::cerr << "Failed to open " << argv[2] << " Perhaps it doesn't exist?\n";
        return 1;
    }

    std::string input_data((std::istreambuf_iterator<char>(input_file)),
            std::istreambuf_iterator<char>());

    part_a = reinterpret_cast<void(*)(std::string)>(dlsym(handle, "part_a"));
    part_b = reinterpret_cast<void(*)(std::string)>(dlsym(handle, "part_b"));
    (void)dlerror();

    std::cout << argv[1] << ":\n";

    if (part_a != nullptr) (*part_a)(input_data);
    if (part_b != nullptr) (*part_b)(input_data);

    dlclose(handle);
}

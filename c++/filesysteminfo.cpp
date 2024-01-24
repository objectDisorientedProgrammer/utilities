// must compile with at least C++17 
#include <filesystem>
#include <iostream>

using std::cout;
using std::endl;

const auto mega{1000000};
const auto giga{1000000000};

void print_size(const std::uintmax_t& size)
{
    cout << size << " bytes (";
    cout << size/mega << " MB; ";
    cout << size/giga << " GB)" << endl;
}

int main(int argc, char* argv[])
{
    const auto dir{"."};
    std::error_code ec;
    
    const std::filesystem::space_info si = std::filesystem::space(dir, ec);
    
    cout << "capacity: ";
    print_size(si.capacity);
    cout << "free: ";
    print_size(si.free);
    cout << "available: ";
    print_size(si.available);
    cout << "used: ";
    print_size(si.capacity - si.free);
    
    return 0;
}

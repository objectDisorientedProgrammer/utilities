#include <cctype> // tolower()
#include <iostream>
#include <string>

using std::cout;
using std::endl;

enum class Animal {pig, chicken, goat, cat, dog, duck, ox};

const std::string getAnimalName(const Animal a)
{
    switch(a)
    {
        // two legged animals
        case Animal::chicken: return "chicken";
        case Animal::duck: return "duck";
        // four legged animals
        case Animal::cat: return "cat";
        case Animal::dog: return "dog";
        case Animal::goat: return "goat";
        case Animal::pig: return "pig";
        case Animal::ox: return "ox";
        default:
            return "Error, invalid animal";
    }
}

int getNumberOfLegs(const Animal a)
{
    int numberOfLegs = 0;

    switch(a)
    {
        // two legged animals
        case Animal::chicken:
        case Animal::duck:
            numberOfLegs = 2;
            break;
        // four legged animals
        case Animal::cat:
        case Animal::dog:
        case Animal::goat:
        case Animal::pig:
        case Animal::ox:
            numberOfLegs = 4;
            break;
        default:
            numberOfLegs = -1;
            break;
    }

    return numberOfLegs;
}

cool isVowel(const char letter)
{
    char c = std::tolower(letter);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void printNumberOfLegs(const Animal a)
{
    const std::string name{getAnimalName(a)};

    cout << "A";
    if (isVowel(name[0]))
        cout << "n";
    cout << " " << name << " has " << getNumberOfLegs(a) << " legs." << endl;
}

int main()
{
    printNumberOfLegs(Animal::cat);
    printNumberOfLegs(Animal::chicken);
    printNumberOfLegs(Animal::ox);

    return 0;
}
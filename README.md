# Animal Shelter Management System

A console-based animal shelter system written in C++, showing the core object-oriented programming concepts: inheritance, abstract classes, polymorphism, manual memory management and exception handling.

Built as the course project for **CMPE 261**.

## Features

- Staff members can **add** and **remove** animals
- Adopters can **adopt** and **return** pets
- **Recursive search** for animals by name
- Tracks the total number of registered animals with a static counter
- Error handling for edge cases: adopting an already-adopted animal, removing an adopted animal, searching for an animal that doesn't exist

## Class design

```
            ShelterUser  (abstract)
            ├── name, userID
            └── displayUserInfo() = 0
                 ▲              ▲
                 │              │
             Adopter       ShelterStaff
         adoptPet()        addAnimal()
         returnPet()       removeAnimal()

  ShelterSystem ──owns──► vector<Animal*>
                ──owns──► vector<ShelterUser*>

  Animal: name, species, animalID, isAdopted, static totalAnimals
```

- `ShelterUser` is abstract: `displayUserInfo()` is a **pure virtual** function, and the class has a **virtual destructor** so derived objects are destroyed correctly through a base pointer.
- `ShelterSystem` owns every `Animal` and `ShelterUser` on the heap and frees them in its destructor.
- `searchAnimal()` delegates to a recursive helper, `searchAnimalRecursive(name, index)`.
- Invalid operations throw `std::runtime_error`.

## Building and running

Requires a C++20 compiler and CMake 3.16+.

```bash
cmake -S . -B build
cmake --build build
./build/animal_shelter
```

On Windows with Visual Studio, the executable is at `build\Debug\animal_shelter.exe`.

Without CMake:

```bash
g++ -std=c++20 src/*.cpp -o animal_shelter
./animal_shelter
```

## Sample runs

`main.cpp` runs three self-contained scenarios:

1. **Setup:** create the system, add users and animals, list everything
2. **Search and adopt:** find an animal, adopt it, try adopting it again (fails), return it, search for an animal that doesn't exist
3. **Remove:** try to remove an adopted animal (throws), return it, then remove it successfully

## Project structure

```
.
├── CMakeLists.txt
└── src/
    ├── main.cpp           # Sample runs
    ├── Animal.h/.cpp
    ├── ShelterUser.h/.cpp # Abstract base class
    ├── Adopter.h/.cpp
    ├── ShelterStaff.h/.cpp
    └── ShelterSystem.h/.cpp
```

## Author

Yağız Efe Çiçekçisoy

## License

[MIT](LICENSE)

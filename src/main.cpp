#include <iostream>
#include <string>
#include <dlfcn.h>

typedef std::string String ;
typedef void (*SubRoutine) (void) ;

enum Error {
    CANNOT_OPEN_FILE_ERROR = 1,
    CANNOT_LOAD_SUBROUTINE = 2
};

int main(int argc, char** argv) {
    std::cout << "C++ dlopen demo" << std::endl ;
    std::cout << "---------------" << std::endl ;

    // Open the library
    String filePath ;
    std::cout << "File name >> " ;
    std::cin >> filePath ;

    void* handle = dlopen(filePath.c_str(), RTLD_LAZY) ;

    if (!handle) {
        std::cerr << dlerror() << std::endl ;
        return CANNOT_OPEN_FILE_ERROR ; 
    }

    String routineSymbol ;
    std::cout << "Call subroutine >> " ;
    std::cin >> routineSymbol ;

    SubRoutine greeting = (SubRoutine) dlsym(handle, routineSymbol.c_str()) ;
    const char* dlsymError = dlerror() ;

    if (dlsymError) {
        std::cout << "Cannot load symbol " << routineSymbol << dlsymError << std::endl ;
        dlclose(handle) ;
        return CANNOT_LOAD_SUBROUTINE ;
    }

    greeting() ;

    dlclose(handle) ;

    return 0 ;
}
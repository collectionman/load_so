This is a simple example code about how to call a extern "C" function using ```<dlfcn.h>``` library in C/C++

You must to follow the next steps to run the program:

    1- First, we have a ```Makefile``` which contains the instructions to build and run the program
    2- Write on the terminal the next command ```make build```, it will takes the files in the ```src``` folder and          generate a './bin' folder with tree files. Two shared objects files ```.so``` (```hello.so``` and ```goodbye.so```)   and the ```main.bin``` file.
    3- Then you can write ```make run``` to execute the program or you can move to the ```bin``` folder by ```cd bin```      and write ```./main.bin``` to achieve the same result.
    4- A prompt message on the terminal will appears requesting the path of one of the .so files (```./bin/hello.so``` or    ```./bin/goodbye.so```)
    5- Finally, you can call the C function written in the .so file.          
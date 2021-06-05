# Slice creator for ovito
* cd build && ./slicer <filename.cfg> <min> <max> <0 or 1 or 2>
* example -> `./slicer dump.cfg -192 -162 0`
* .cfg file will be created in build folder itself

**Do not move any temporary files or head.txt**

#### program takes at least 4s because it uses some linux scripts for concatenating header file

#### Best way would be to create a bash script to convert all files at once
### Compiling without cmake or make 
`cp head.txt ../ && g++ -o slicer main.cpp`


### Modifying code
* reader.h is just a struct for point3d
* change anything you want in main.cpp for creating files
* cd build && make (sudo apt-get install make , if not available)
* if you want to use any other library, you must add in CMakeLists.txt and then run `cd build && cmake ..` and then `make`

### FIXME:
* do not use linux subprocesses commands

### TODO : 

* Make slicer platform independent
* Allow adding various lammps files 

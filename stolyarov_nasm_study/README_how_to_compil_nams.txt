// on linux
nasm -f elf name_of_file.s
ld -m elf_i386 -s -o name_of_file name_of_file.o

// find  how to compil on macOS
nasm -f elf name_of_file.s
ld -e name_of_execut_file 


python3 ingen.py > in.txt
g++ brute.cpp
./a.out < in.txt > out1.txt
g++ c.cpp
./a.out < in.txt > out2.txt
cmp out1.txt out2.txt
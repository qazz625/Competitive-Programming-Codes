python3 ingen.py > in.txt
g++ 1516d.cpp -O2
time ./a.out < in.txt > out1.txt
g++ brute.cpp -O2
time ./a.out < in.txt > out2.txt
cmp out1.txt out2.txt
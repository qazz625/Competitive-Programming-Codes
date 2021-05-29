python3 ingen.py > in.txt
g++ densegrp.cpp
time ./a.out < in.txt > out1.txt -O2
g++ brute.cpp
time ./a.out < in.txt > out2.txt -O2
python3 checker.py
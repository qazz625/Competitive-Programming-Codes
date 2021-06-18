python3 ingen.py > in.txt
g++ mfss.cpp -O2
time ./a.out < in.txt > out.txt
g++ mfss2.cpp -O2
time ./a.out < in.txt > out2.txt
cmp out.txt out2.txt
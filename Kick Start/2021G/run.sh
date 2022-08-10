python3 ingen.py > in.txt
time python3 brute.py < in.txt > out1.txt
time pypy3 b.py < in.txt > out2.txt
time cmp out1.txt out2.txt

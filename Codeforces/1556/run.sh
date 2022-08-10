python3 ingen.py > in.txt
python3 brute.py < in.txt > out1.txt
time g++ 1556c.cpp
./a.out < in.txt > out2.txt
diff out1.txt out2.txt
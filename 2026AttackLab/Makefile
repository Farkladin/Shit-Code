run:
	g++ x.cpp -std=gnu++17 -o x
	./x > solutions.txt

run1:
	./x 1

run2:
	g++ x.cpp -std=gnu++17 -o x
	./x 2 > payload2-hex
	./hex2raw < payload2-hex > payload2
	./ctarget -q < payload2

run3:
	g++ x.cpp -std=gnu++17 -o x
	./x 3 > payload3-hex
	./hex2raw < payload3-hex > payload3
	./ctarget -q < payload3

run4:
	g++ x.cpp -std=gnu++17 -o x
	./x 4 > payload4-hex
	./hex2raw < payload4-hex > payload4
	./rtarget -q < payload4
	
run5:
	g++ x.cpp -std=gnu++17 -o x
	./x 5 > payload5-hex
	./hex2raw < payload5-hex > payload5
	./rtarget -q < payload5

submit:
	./ctarget < payload1
	./ctarget < payload2
	./ctarget < payload3
	./rtarget < payload4
	./rtarget < payload5


tool:
	g++ y.cpp -std=gnu++20 -O2 -o finder
	

all: B7 proves

B7: B7.cc
	g++ B7.cc -o B7

proves: proves.cc
	g++ proves.cc -o proves
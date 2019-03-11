#include "sort.h"
using namespace std;

int main(int argc,char **argv) {
	int n;
	stringstream ss(argv[3]);
	ss>>n;
	Sort first(argv[1],n);
	switch (argv[4][0]){
		case 'b': first.method(1);break;
		case 's': first.method(2);break;
		case 'm': first.method(3);break;
		case 'q': first.method(4);break;
		case 'r': first.method(5);break;
	}
	first.printdt(argv[2]);
	return 0;
}
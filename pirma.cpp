#include <iostream>
#include <fstream>
#include <vector>

// int a = 1, c = 155, m = 729;  // seka kai m = 729
int a = 633, c = 777, m = 1264;
// int a = 7, c = 7, m = 10;

int lcg(int seed){

	int randomNumber;
	randomNumber=(a*seed+c)%m;
	return randomNumber;
}

int main(int argc,char *argv[]) {
	std::ofstream outfile ("output.dat");
	int seedNumber;
	  
	seedNumber=atoi(argv[1]);

	for(int i=0; i<=m; i++) {
	  seedNumber=lcg(seedNumber);
	  float x = (float)seedNumber / (float)m;
	  outfile << x << std::endl;
	}
	outfile.close();
  return 0;
}

// 1111
#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <map>
/*3. Naudodami sugeneruot¡ geresni¡j¡ pseudoatsitiktiniu skai£iu sek¡
sumodeliuokite du atsitiktinius dydºius, vien¡ pasiskirs£iusi pagal geometrini
skirstini su parametru p = 0.1, o kit¡ parinkite patys.*/

double p = 0.1;
void geometrinis_skirstinys(double p);
void normaliai_pasiskirstes_dydis();

int main(int argc,char *argv[]) {
	geometrinis_skirstinys(p);
	normaliai_pasiskirstes_dydis();
  return 0;
}

// N ← ln U / ln(1 − p).
 void geometrinis_skirstinys(double p) {
	std::vector<float> u;
	std::fstream myfile("output.dat", std::ios_base::in);

    float a;
    while (myfile >> a) {
        u.push_back(a);
    }
    myfile.close();

    std::ofstream outfile ("outputGeometric.dat");

    for(int i = 0; i < u.size(); i++) {
    	double N = log(u[i]) /  log(1 - p);
    	outfile << N << std::endl;
    	// std::cout << N << std::endl;
    }
    outfile.close();
 }

// Algoritmas sugeneruoja du normaliai paiskirsciusius atsitiktinius dydzius X1 ir X2
 void normaliai_pasiskirstes_dydis() {
 	std::vector<float> u;
	std::fstream myfile("output.dat", std::ios_base::in);

    float a;
    while (myfile >> a) {
        u.push_back(a);
    }
    myfile.close();
    std::vector<double> x1;
 	std::vector<double> x2;
    for(int i = 0; i < u.size()-1; i++) {
    	double s = 0, v1 = 0, v2 = 0;
    	v1 = 2 * u[i] - 1;
    	v2 = 2 * u[i+1] - 1;
    	s = v1*v1 + v2*v2;
    	if(s >= 1) {
    		continue;
    	} else {
    		if(s == 0) { x1.push_back(0); x2.push_back(0);}
    		else {
	    		double root = (double)(-2) * log(s)/s;
	    		x1.push_back(v1 * sqrt(root));
	    		x2.push_back(v2 * sqrt(root));
    		}
    	}
    }

    std::ofstream outfile ("outputPolar.dat");
    for(int i = 0; i < x1.size(); i++) {
    	outfile << x1[i] << ", " << x2[i] << std::endl;
    }
    outfile.close();
 }
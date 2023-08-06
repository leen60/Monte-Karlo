/*4. Naudodami sugeneruot¡ geresni¡j¡ pseudoatsitiktiniu skai£iu sek¡ ir
parinkdami tankius (tolygiai pasiskirs£iusio intervale [0, 2] atsitiktinio dydºio
ir kit¡ savo nuoºi	ura) suskai£iuokite integral¡:*/
#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <map>

double func(double val);

int main(int argc,char *argv[]) {
	std::vector<float> u;
	std::fstream myfile("output.dat", std::ios_base::in);

    float a;
    while (myfile >> a) {
        u.push_back(a);
    }
    myfile.close();

    double result = 0.0;
    for(int i = 0; i < u.size(); i++) {
    	double val = 2 * u[i];
    	result = result + func(val);
    }
    std::cout << result * 2 / u.size() << std::endl;
    // interval_cal();
	return 0;
}

double func(double val) {
	return (val + pow(val, 5))/ (1 + val);
}

#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <map>

int nGaps = 9;
float lower = (float)3/(float)4, upper = 1;

void intervaluTestas();
void keliniuTestas();


int main(int argc,char *argv[]) {

	std::cout << "Intervalu testas: " << std::endl;
	// intervaluTestas();
	std::cout << "Keliniu testas: " << std::endl;
	keliniuTestas();
	return 0;
}

void intervaluTestas() {
	std::vector<float> u;
	std::fstream myfile("output.dat", std::ios_base::in);

    float a;
    while (myfile >> a) {
        u.push_back(a);
    }
    myfile.close();

    // INTERVALU TESTAS
	bool running = true;
	int j = -1, s = 0, r = 0, t = 7;
	std::vector<int> count(t+1, 0); 
	// std::cout <<"j " << "r " << "t "  << "s "  << " nGaps " << lower << ", " << upper << ")" << std::endl;
	while(running) {
		// std::cout << j << " " << r << " " << t << " " << s << " " << nGaps << " [" << lower << ", " << upper << ")" << std::endl;
		j++;
		std::cout << u[j] << " ";
		if((u[j] >= lower) && (u[j] < upper)) {
			std::cout << "Radom intervala " << u[j] << " ilgio " << r << std::endl;
			if (r >= t) {
				count[t] = count[t] + 1;
			} else {
				count[r] = count[r] + 1;
			}
			s = s+1;
			if(s < nGaps) {
				r = 0;
			} else {
				running = false;
			}
		} else {
			r = r+1;
		}
	}

	for (int i = 0; i < count.size(); i++)
    	std::cout << i << " " << count[i] << std::endl;

    float p = upper - lower;
    std::vector<float> prop(t+1, 0); 
    float base = (float)1 - p;
    for (int i = 0; i < prop.size(); i++) {
    	prop[i] = p * (pow(base, i));
    	std::cout << i << " " << prop[i] << std::endl;
    }

    // χ2 kriterijus

    float Xn;
    for (int i = 0; i < t+1; i++) {
    	float up = pow((count[i] - nGaps*prop[i]), 2);
    	float d = nGaps*prop[i];
    	float div = up/d;
    	Xn = Xn + div;
    }

    std::cout << "Kriterijus " << Xn << std::endl;
}

int factorial(int n) {
    return (n==1 || n==0) ? 1: n * factorial(n - 1); 
}

void keliniuTestas() {
	std::vector<float> u;
	std::fstream myfile("output.dat", std::ios_base::in);
	u.push_back(-2);
    float a;
    while (myfile >> a) {
        u.push_back(a);
    }
    myfile.close();

    // KELINIU TESTAS
    int t = 3; // PASIRINKTI KELINIO DYDI
    bool running = true;
    std::vector<int> f_val;
    int j = 0, k = 1;
    int n = u.size() / t;
    std::cout << std::endl;
    while(running) {
    	if(k >= n) running = false;
    	int f = 0;
    	int r = t;
    	float perm[t+1];
    	perm[0] = -2;
    	std::vector<int> permutations;
    	while(r > 1) {

    		for(int i = 1; i <= r; i++) {
    			perm[i] = u[j+i];
    		}
    		int maxElementIndex = std::max_element(perm, perm + r + 1) - perm;
    		permutations.push_back(maxElementIndex);
    		f = f * r + maxElementIndex - 1;
    		float swap = u[r+j];
    		u[j+r] = u[j+maxElementIndex];
    		u[j+maxElementIndex] = swap;
    		r = r - 1;
    	}

    	f_val.push_back(f);
    	j = j + t;
    	k++;
    }

	std::map<int , int> h;
	int N = u.size();

	for(int i = 0 ; i < f_val.size() ; i++)
  		h[f_val[i]]++;
    // χ2 kriterijus

    double Xn = 0.0;
    int fac = factorial(t);
    double prop = 1.0 / fac;
    for (const auto & p : h) {
    	std::cout << p.first << " " << p.second  << " " << N *prop << std::endl;
    	double up = pow(p.second, 2);
    	double div = up/prop;
    	Xn = Xn + div;
    }
    Xn = (Xn - N)/N;
    std::cout << "Kriterijus " << Xn << std::endl;
}
#include <ctime>
#include <cmath>
using namespace std;
class Timer {
public:
	Timer(int k,int r_a,int r_b,float s_a);
	void setStart(int kk,int raa,int rbb,float saa);
	void setE();
	double getR_A();
	double getR_B();
	float S_A;
	double E_A;
	double E_B;

private:
	int K;
	double R_A;
	double R_B;
};

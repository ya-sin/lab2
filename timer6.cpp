#include "timer6.h"
Timer::Timer(int k,int r_a,int r_b,float s_a) {
	setStart(k,r_a,r_b,s_a);
}
void Timer::setStart(int kk,int raa,int rbb,float saa) {
	K = kk;
	R_A = raa;
	R_B = rbb;
	S_A = saa;
}
void Timer::setE(){
	E_A = 1/(1+pow(10,(R_B-R_A)/400));
	E_B = 1/(1+pow(10,(R_A-R_B)/400));
	}
double Timer::getR_A(){
	return  R_A + K * (S_A-E_A);
	}
double Timer::getR_B(){	
	return  R_B + K * ((1-S_A)-E_B);
	}


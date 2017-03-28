#include <iostream>
#include <unistd.h>
#include "timer6.h"
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <sstream>
using namespace std;
int main() {
	ifstream inFile("file.in",ios::in);
	if(!inFile){
		cerr<<"Failed opening"<<endl;
		exit(1);
	}
	char *buffer = new char[50];
	int i=0,j=0,k=2;
	float tmp[100][3];
	while(inFile.getline(buffer,50)){
		stringstream ss3(buffer);
		while(ss3>>tmp[i][j]){
			j++;
		}
		i++;
		j=0;
	}
	Timer tmr2(tmp[0][0],tmp[0][1],tmp[0][2],tmp[1][0]);
	tmr2.setE();
	ofstream outFile("outfile",ios::out);
	if(!outFile){
		cerr<<"Failed opening"<<endl;
		exit(1);
	}
	outFile<<tmp[0][1]<<"\t"<<tmp[0][2]<<endl;
	while(k<i+1){
		int RA = round(tmr2.getR_A());
		int RB = round(tmr2.getR_B());
		outFile<<RA<<"\t"<<RB<<endl;
		tmr2.setStart(tmp[0][0],RA,RB,tmp[k][0]);
		tmr2.setE();
		k++;
	}
	return 0;
}

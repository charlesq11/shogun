#ifndef __GUIHMM__H
#define __GUIHMM__H

#include "hmm/HMM.h"

class CGUIHMM
{
public:
	CGUIHMM();
	~CGUIHMM();

	bool new_hmm(char* param);
	bool baum_welch_train(char* param);
	bool linear_train(char* param);
	bool one_class_test(char* param);
	bool test_hmm(char* param);
	bool append_model(char* param);
	bool add_states(char* param);
	bool set_hmm_as(char* param);

protected:

	bool converge(double x, double y);
	void switch_model(CHMM** m1, CHMM** m2);

	CHMM* working;
	CHMM* working_estimate;

	CHMM* pos;
	CHMM* neg;
	CHMM* test;

	REAL PSEUDO;
	int M;
	int ORDER;
	REAL EPSILON;

	int iteration_count;
	int ITERATIONS;
	int conv_it;
};
#endif

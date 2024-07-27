#include<stdio.h>
#include<math.h>
//aX2+bX+c=0;
struct number{
	double re;
	double im;
};
struct number *Solve(double a,double b,double c){
	struct number *root;
	root=malloc(2*sizeof(struct number));
	double delta=pow(b,2)-4*a*c;
	if(delta<0){
		delta*=-1;
		root[0].re=((-1)*b)/(2*a);
		root[1].re=((-1)*b)/(2*a);
		root[0].im=sqrt(delta)/(2*a);
		root[1].im=sqrt(delta)/(2*a);
	}
	else {
		root[0].re=((-1)*b+sqrt(delta))/(2*a);
		root[1].re=((-1)*b-sqrt(delta))/(2*a);
		root[0].im=0;
		root[1].im=0;
	}
	//free(root);
	return root;
}

int main(){
	struct number *root;
	root=malloc(2*sizeof(struct number));
	root=Solve(1,3,-18);
	printf("Root1: %lf + %lfi ",root[0].re, root[0].im);
	printf("Root2: %lf - %lfi ",root[1].re, root[1].im);
	free(root);
	return 0;	
}

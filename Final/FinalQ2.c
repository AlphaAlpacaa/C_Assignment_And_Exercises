#include<stdio.h>
#include<math.h>

struct number{
	double reel;
	double imaginare;
};
struct number *Solve(double a,double b,double c){
	struct number *root;
	root=malloc(2*sizeof(struct number));
	double delta=b*b-4*a*c;
	if(delta>=0){
		root[0].reel=((-1)*b+sqrt(delta))/(2*a);
		root[1].reel=((-1)*b-sqrt(delta))/(2*a);
		root[0].imaginare=root[1].imaginare=0;
	}
	else{
		root[0].reel=((-1)*b)/(2*a);
		root[1].reel=((-1)*b)/(2*a);
		root[0].imaginare=root[1].imaginare=sqrt(fabs(delta))/(2*a);
	}
	return root;
}

int main(){
	struct number *root;
	root=malloc(2*sizeof(struct number));
	root=Solve(4,1,3);
	printf("Root1: %.5f + %.5fi \n",root[0].reel, root[0].imaginare);
	printf("Root2: %.5f - %.5fi ",root[1].reel, root[1].imaginare);
	free(root);
	return 0;	
}

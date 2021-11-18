//aqui se crea el codigo para el Jacobi 
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int Jacobi(int n, double **A, double *b, int *xi, double tol, int MaxIt){
	
	int i, j, k = 0;//contadores usados para nuestro ciclo for.
	double *x=NULL;  //apuntador de nuestro vector solucion aproximado 
	x = (double *) malloc(n*sizeof(double));
	if (x==NULL){
		perror("ERROR. No hay sufuciente memoria");
		exit(EXIT_FAILURE);
	}
	//variable para analizar el error de la aproximación.
	double err;

	while (k<MaxIt,k++){
		for (i=0;i<n;i++){
			//variables para guardar la suma o la diferencia de las dos aproximaciones guardadas en x
			double sum, diff;
			sum=b[i];
			for (j=0;j<n;j++){
				sum=sum-A[i][j]*xi[j];  //operacion dada por el metodo
			}
			sum=sum+A[i][i]*xi[i];
			x[i]=sum/A[i][i];
			
			diff=x[i]-xi[i];
			err=err+diff*diff;
		}
		//se comprueba si cumple la condicion de convergencia 
		if (err<tol){
			break;
		//se prepara para realizar la siguiente iteración	
		} else{
			xi[i] = x[i];
			
		}
	}
	return k;
}



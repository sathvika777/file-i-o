#include<stdio.h>

void read_data(FILE *ptr,int d[],int size){

    for(int i=0;i<size;i++){

        if(i!=0){

            fscanf(ptr,"%d",&d[i-1]);

        }

    }

}

double avg(int d[],int size){

    double avg;

    for(int i=0;i<size;i++){

        if(i!=0)

            avg+=d[i];

    }
return (avg/size);

}

int max(int d[],int size){

	int max=d[1];

    	for(int i=0;i<size;i++){

        	if(i!=0){

            		if(max<d[i])

                		max=d[i];

        	}

    	}
	return max;

}

void print_data(int d[],int size,FILE *ptr1,FILE *ptr2){
    
	printf("The given %d numbers are",size);

    	for(int i=0;i<size;i++){

        	if(i!=0)
		{

            		printf("%d\t",d[i]);

        	}	

    	}
	printf("\n");

    	printf("Average of above Numbers : %f\n",avg(d,size));

    	printf("Maximum of above Numbers : %d\n",max(d,size));

    	fprintf(ptr2,"Average of above Numbers : %f\n",avg(d,size));

    	fprintf(ptr2,"Maximum of above Numbers : %d\n",max(d,size));

}

int main()
{

	FILE fpr1;

	FILE fpr2;

	fpr1 = fopen("myhw.txt", "r");

	fpr2=fopen("answer-hw3.txt","w");

	if(fpr1 == NULL|| fpr2==NULL)

   	{	
      
		printf("Error!");
   
      	exit(1);
        }

	int size;

	fscanf(fpr1,"%d",&size);

	int data[size]={0,0};

	read_data(fpr1,data,size);

	print_data(data,size);

	return 0;

}

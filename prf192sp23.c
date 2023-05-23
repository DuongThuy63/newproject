#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include <ctype.h>
#define MAX_NAME 100
int menu();
float DTHinhThang(float top_edge, float bottom_edge, float height);
float tongbieuthuc(int q, float x);
void generateIntArr(int *arr, int n);
void displayIntArr(int *arr,int n);
void swap(int *a, int *b);
void toLowerCase(char str[]);
void createEmail(char fullname[], char email[]);
int main(){
	int luaChon;
	float top_edge, bottom_edge, height;
	int *arr;
	int n;
	char fullname[MAX_NAME];
    char email[MAX_NAME];
    char a[100];
    int q;
    float x;
    NhapLai:
	do{
		luaChon=menu();	
		switch(luaChon){
			case 1:
				printf("Top edge = ");
				scanf("%f", &top_edge);
				printf("Bottom edge = ");
				scanf("%f", &bottom_edge);
				printf("Height = ");
				scanf("%f", &height);
				printf("Dien tich hinh thang = %0.2f\n", DTHinhThang(top_edge, bottom_edge, height));
				break;
			case 2:
				printf("Nhap vao mot so nguyen n: "); 
    			scanf("%d", &q);
    			printf("Nhap vao x: ");
    			scanf("%f", &x); 
    			float tong = tongbieuthuc(q, x);
    			printf("Tong cua bieu thuc da cho la: %f\n", tong);
    			break;
			case 3:
				arr = (int*)malloc(n*sizeof(int));
				printf("Nhap vao so luong phan tu: ");
				scanf("%d",&n);
				generateIntArr(arr,n);
				printf("\nMang ngau nhien la ");
				displayIntArr(arr,n);
				break;
			case 4:
				printf("Nhap MSSV: ");
				scanf("%s", a);
    			printf("Nhap vao ho ten cua hoc sinh: \n");
    			fflush(stdin);
    			fgets(fullname, MAX_NAME, stdin);
    			createEmail(fullname, email);
    			printf("Email cua hoc sinh la: %s\n", email);
    			break;
    		case 5:
    			printf("Thanks for your choice!");
    			exit(0);
    		default:
    			printf("Error! Please input again!");
    			goto NhapLai;
		}
		}
		while(luaChon!=0);
}
int menu(){
	int luaChon;
	printf("\n=========MENU============\n");
	printf("\n1.Calculate area of a trapezoid\n");
	printf("\n2.Calculate the sum of arithmetic sequence\n");
	printf("\n3.Random array\n");
	printf("\n4.Studen's email\n");
	printf("\n5. Quit\n");
	printf("===========================");
	printf("\nWhich one will you choose?");
	scanf("%d", &luaChon);
	return luaChon;
}
void generateIntArr(int *arr, int n){
	int i;
	srand(time(0));
	int min=0;
	int max= 1000;
	for(i=0; i<n ; i++){
		*(arr+i) = rand()% (max-min+1) + min;
	}
}
void displayIntArr(int *arr, int n){
	int i;
	for(i=0;i<n; i++){
		printf("\na[%d] = %d \n",i,*(arr+i));}
}
void swap(int *a, int *b){
	int tam = *a; 
	*a = *b; 
	*b = tam; 
}
float DTHinhThang(float top_edge, float bottom_edge, float height){
	float dienTich;
	if(top_edge <=0 && bottom_edge <=0 && height <=0){
		return -1;
	}
	else{
		dienTich = (top_edge + bottom_edge)*height/2;
		return dienTich;
	}
}
void toLowerCase(char str[]) {
    int i = 0;
    while (str[i]) {
        str[i] = tolower(str[i]);
        i++;
    }
}

void createEmail(char fullname[], char email[]) {
    char lastname[MAX_NAME];
    char firstname[MAX_NAME];
    char middlename[MAX_NAME];
    
    sscanf(fullname, "%s%s%[^\n]", firstname, middlename, lastname);
    
    toLowerCase(lastname);
    toLowerCase(middlename);
    toLowerCase(firstname);
    
    sprintf(email, "%s%s%s@fpt.edu.vn", lastname, middlename, firstname);
}
float tongbieuthuc(int q, float x) {
    int i;
    float sum = 0.0, sign = 1.0;
    float mauso = 0.0;
    float temp;
    for(i = 1; i <= q; i++) {
        mauso += i;
        sign = -sign;
        temp = sign * pow(x, i)/mauso;
        sum += temp; 
    }
    return sum;
}

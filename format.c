#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>


int binToInt(char *a) {
  int i; 
   int numSign =0;
  int q= 31;
  int dig = 32;
 double power;                                                                                                                                         
  for (i = 0; i<32; i++) {
    if(dig == 32 && a[i] == '1'){
power = pow(2,q);   
   numSign = numSign - power;
    }
    else if(a[i] == '1'){
	power = pow(2, q);
      numSign = numSign + power;
          
    }
    dig--;
    q--;
  }
  return numSign;
}

double strToInt(char a[]) {
  int i;
double numSign;
  double q = 0;
  numSign = 0;
  // char *ptr = a;                                                                                                                                                                                                 // printf("Str: %s\n", ptr);                                                                                                                                                                                     // long len = strlen(ptr);                                                                                                                                                                                          // printf("Len: %ld\n", len);                                                                                                                                                                                     
  
  for (i = 0; i < 32; i++) {
    // printf("value of i: %ld\n", i);                                                                                                                                                                            
    // printf("A[i]= %c\n", a[i]);                                                                                                                                                                                
    q = q * 10 + (a[i] - '0');
    //printf("Value of long: %ld\n", q);                                                                                                                                                                          
  }

  return q;
}


int getExp(char *bin){
  int i;
  int q = 7;
  int exponent = 0;
  for(i=1; i<9;i++){
    if(bin[i] == '1'){
       exponent = exponent + pow(2,q);
       } 
      q--;
  }

    printf("Exponent is: %d\n", exponent);
    exponent -= 127;  
return exponent;
}

float getAns(char *p, int exp, int neg){
  char *ptr = p;
  int i;
  char *tempptr;

  //printf(" exponent val: %d \n", exp); 
  //printf("Value of neg: %d\n", neg);

  ptr = ptr +9;
  //printf("ptr: %s\n", ptr);
  //*ptr = ptr[9];
  //printf("ptr: %s\n", ptr);
  int bit;

  if(exp < 0){
    tempptr = ptr;
  }
  else{
    tempptr = ptr+exp -1;
  }
  double power;
int dL; //the digits to the left of the decimal point.
dL = 0;
  for (i = 0;i < exp;i++)
    {
      bit= *tempptr - '0';
      power = pow(2,i);
      dL += bit * power;
      tempptr--; 
    }
 if (exp >= 0)
    {
	power = pow(2, exp);
      dL += power;
      ptr += exp;
    }  

bit = 0;

  float dR = 0.0;   //find the digits to the right of the decimal

  i=1;
  if(exp > -127 && exp < 0 )   //calculating the numbers to the right of the decimal for when the exp is -
    {
      for(i = 1 -exp; *ptr != '\0'; i++)
	{
	power = pow(2, -1 *i);

	  bit = *ptr-'0';
	  dR+= power * bit;
	  ptr++;
	}
	
power = pow(2, exp);
  dR += power;

    }
  else
    {
      for(i = 1;*ptr !='\0';i++)  //calculating the numbers to the right of the decimal for when the exp is +
	{
	//printf("*ptr: %s\n", ptr);
	power = pow(2, -1* i);
	  bit = *ptr-'0';
	  dR+= power *bit;
	//printf("DR= %g\n", dR);
	  ptr++;
	}
    }


 
 float answer = dL + dR;
  //printf("answer right = %f ",dR);
int e = 0;  
if(answer>1.0)
    {
      while(answer > 1.0) 
	{
	e--;
	  answer/=10;  //moving the decimal point 
	}
      answer *= 10;
      if(neg == 1)
      answer *= -1;
      printf("%fe%d \n",answer , e+1);
    }
  else if(answer==0)
    {
      if(neg == 1)
      answer *= -1;
      printf("%fe%d \n",answer , e);
    }
  else
    {
      while(answer < 1.0) 
	{
	  answer*=10;
	  e++;
	}
	if(neg == 1)
      answer *= -1;
      printf("%fe%d \n",answer , e*-1);
    }
  return answer;
  //return tostring(answer);
} //bin_float

int main (int argc, char **argv){

  //printf("argc: %d\n", argc);
  //printf("ARgv[0]: %s\n", argv[0]);
  //printf("ARgv[1]: %s\n", argv[1]);
  
//char *binStr = malloc (sizeof(char) *32);
 char * binStr = argv[1];
 char *type = argv[2];
printf("argc: %d\n", argc);
int length = strlen(binStr); //error
  if (length != 32){
    fprintf(stderr, "ERROR: Not correct length. Len= %d\n", length);
    //printf("current lenth: %d\n", length);
    return 0;
  }
  if(argc != 3){  //error
    fprintf(stderr, "ERROR: Incorrect number of arguments\n");
    return 0;
  }
 int len = strlen(type);
 int i;
 for(i=0;i<len;i++){
   type[i] = tolower(type[i]);
 }
 if(strcmp(type, "int") != 0 && strcmp(type, "float") != 0){  //Error handling
   fprintf(stderr, "ERROR: Invalid type entered\n");
   return 0;
 } 
for(i=0;i<length;i++){
if( binStr[i] != '1' && binStr[i] != '0'){
	fprintf(stderr, "ERROR: Not a binary number\n");
	return 0;
}
}
 
  int binInt;
  //printf("binStr is :%s\n", binStr);
  if(strcmp(type, "int") == 0){    //conversion of binary into int w/ twos compliment
  binInt = binToInt(binStr);
 printf("%d\n", binInt);
 return 0;
  } 

  if(strcmp(type, "float") == 0){
    int neg; //0=+, 1 = -    
if(binStr[0] == '0'){
  neg = 0;
    }
 else{
   neg =1;
 }
 int exp = getExp(binStr);
 // getAns(binStr, exp, neg);
 float mValue = getAns(binStr, exp, neg);

 if(exp==128 && neg == 1 &&  mValue == 0.000000) {

   printf("ninf\n");
   return 0;
 }
 if(exp==128 && neg == 0 &&  mValue == 0.000000) {


   printf("pinf\n");
   return 0;
 }
 if(exp==128 && neg == 1 &&  mValue != 0) {

   printf("-NaN\n");
   return 0;
 }
 if(exp==128 && neg == 0 &&  mValue != 0) {
   printf("+NaN\n");
   return 0;
 }
 if(exp== -127 && neg == 1 && mValue == 0) {
   printf("-0.0e0\n");
   return 0;
 }
 if(exp==-127 && neg == 0 && mValue == 0) {
   printf("+0.0e0\n");
   return 0;
 }

 return 0;

  }

  return 0;
}

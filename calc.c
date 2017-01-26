//Written by David Alummoottil


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

struct Number_ {
  char *type; //o for octal, b for binary etc..
 };

typedef struct Number_ Number;

 long octToDec(long octNum){
  
long decNum = 0;
 long o = 0;
 
  while(octNum!=0){
    decNum = decNum + (octNum % 10) * pow(8,o++);
    octNum = octNum/10;
  }
  return decNum;

}

long decToOct(long decNum){
  long remainder;
  long j=1;
  long octNum=0;

  while (decNum!=0)
    {
      remainder = decNum%8;
      decNum/=8;
      octNum += remainder * j;
      j*=10;
    }
  return octNum;

}
/*Converts a binary number into decimal format*/ 

long binToDec(long binNum){
  long decNum = 0;
  long i = 0;
  long remainder;

  while(binNum != 0){
    remainder = binNum%10;
    binNum /= 10;
    decNum += remainder * pow(2, i);
    ++i; 
  }
  return decNum;
}

/*Converts a Decimal number into Binary format*/ 

long decToBin(long decNum){
  long rem; 
  long j=1;
  long binNum=0;
  while (decNum!=0)
    {
      rem=decNum%2;
      decNum/=2;
      binNum+=rem*j;
      j*=10;
    }
  return binNum;
}

/*Converts a Hexadecimal number into decimal format*/ 

long hexToDec(char *hexNum){
  long decimalNumber = 0;
  char hexDigits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
			'9', 'a', 'b', 'c', 'd', 'e', 'f'};  
  long i, j, power=0; 
 
  for(i=strlen(hexNum)-1; i >= 1; i--) {
    for(j=0; j<16; j++){
      if(hexNum[i] == hexDigits[j]){
       	decimalNumber += j*pow(16, power);
}
    }
    power++;
  }  
 
  return decimalNumber;
  return 0;
}

/*Converts a decimal number into hexadecimal format*/ 

char* decToHex(long decNum){
  int quotient;
  long i=0;
  long j;
  long k;
  int remainder;
  if(decNum <0){
    decNum = -decNum;
  }
  char hexadecimalNumber[100];
  char *hexNum = hexadecimalNumber;
  quotient = decNum;
  char hexDigits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
                        '9', 'a', 'b', 'c', 'd', 'e', 'f'};

  while(quotient != 0) {
    if(quotient>15){
    remainder = quotient % 16;
    //To convert integer into character
    for(j=0;j<16;j++){
      if(j == remainder){
	
	hexNum[i] = hexDigits[j];
	i++;
      }
    }
    }
    else{
      for(k=0;k<16;k++){
	if(k == quotient){
	  hexNum[i] = hexDigits[k];
	  i++;
	  }     
 }

    }
    quotient = quotient / 16;
  }
   
  long len = strlen(hexNum);
 
  char *hexFinal = malloc (sizeof(char) *len); //  free the memory
  long m;
  long n = 0;
 for (m = len -1 ;m>= 0;m--){
   hexFinal[n] = hexNum[m];
  n++;
 
 }
  return hexFinal;

}

long decConvert(long num, char* type){
 long dec;
  long ret;
  
  ret = strcmp(type, "d");
  if(ret == 0){  
    return num;
  }
  ret = strcmp(type, "o");
  if(ret == 0){
    dec = octToDec(num);
    return dec;
  }
  ret = strcmp(type, "b");
  if(ret == 0){
    dec = binToDec(num);
    return dec;
  }
  return 0;

} 

long add(long num1, long num2){
  long sum = num1+num2;
  return sum;

}

long subtract(long num1, long num2){
  long difference = num1-num2;
  return difference;

}

long multiply(long num1, long num2){
  long product = num1*num2;
  return product;

}

long validCheck(char *string){ //return 0 for not valid, 1 for valid, 2 for negative valid fucntion, 3 for valid hex 4 for invalid 5 for neg valid hex
  char fc = string[0];
  char sc = string[1];
  long i;
  long len = strlen(string);
  long hex =0;
  if(fc=='-'){
    if(sc == 'd' || sc == 'o' || sc == 'x' || sc == 'b'){
      for(i=2;i<len; i++){
	if(isxdigit(string[i]) == 0){ //is not a valid digit
	return 0;}
	if((sc == 'o' && string[i]=='8') || (sc == 'o'&&string[i]== '9')){
	  return 4;
	}
	if((sc == 'b' && string[i]!='0') && (sc == 'b' && string[i] != '1')){
	  return 4;
	}
	if(isxdigit(string[i]) != 0 && sc == 'x'){
	hex =1;}
	if(isxdigit(string[i]) != 0 && sc != 'x' && isdigit(string[i]) == 0)
	return 0;
      }
 if(hex == 0){
	 return 2;
    }
    else{
      return 5;
}
      return 2;
    }
    return 0; // fc= '-' but sc != doxb
  }
  else if(fc == 'd' || fc == 'o' || fc == 'x' || fc == 'b'){
    for(i=1;i<len; i++){
      if(isxdigit(string[i]) == 0) //is not a valid digit
	return 0;
	if(isxdigit(string[i]) != 0 && fc != 'x' && isdigit(string[i]) == 0)
	return 0;
      if(isxdigit(string[i]) != 0 && sc == 'x')
	hex =1;
      if((fc == 'o' && string[i]=='8') || (fc == 'o'&&string[i]== '9')){
	return 4;
      }
      if((fc == 'b' && string[i]!= '0') && (fc == 'b' && string[i] != '1')){
	return 4;
      }
    }
    if(hex == 0){
	 return 1;
    }
    else{
      return 3;
}
  }
  return 0;  
}

 long strToInt(char a[]) {
  long i,j, numSign;
  long q=0;
  numSign = 0;
  if (a[0] == '-') {  // Handle negative integers
	numSign = -1;   
 j=2;
  }
  else
    j=1;
 
  for (i = j; a[i] != '\0'; i++) {
       q = q * 10 + (a[i] - '0');
  }
 
  if (numSign == -1) {
    q = -q;
  } 
  return q;
}

void destroyMem( Number *testNum){

  free (testNum->type);
free(testNum);
  
}

int main( int argc, char ** argv){  
  if(argc != 5){ //check to see if anything is entered in command line                                                                                                                                     
    fprintf(stderr,"Command line does not have correct number of arguments. \n");
    return -1;
  }
 char * operation = argv[1];
 if(strcmp(operation, "+")!= 0 && strcmp(operation, "-") != 0 && strcmp(operation, "*") != 0){
    fprintf(stderr, "Operator not given.\n");
    return -1;
  }
  char *outType = argv[4];
  if(strcmp(outType, "d") != 0 && strcmp(outType, "x") != 0 && strcmp(outType, "o") != 0 && strcmp(outType, "b") != 0){
    fprintf(stderr, "Invalid output type given. \n");
    return -1;
  }

  Number *testNum1; //creating struct for the two numbers
  testNum1 = (Number*) malloc (sizeof(Number));
  Number *testNum2;
  testNum2 = (Number*) malloc (sizeof(Number));
    
  long len1 = strlen(argv[2]); //copying command line args into strings
  char *string1 = malloc(sizeof(char) *len1 +1 ); 
  long len2 = strlen(argv[3]);
  char *string2 = malloc(sizeof(char) * len2 +1);
  strcpy(string1, argv[2]); 
int length = strlen(string1);  
int w;
for(w=0;w<length; w++){
  string1[w] = tolower(string1[w]);	
}

  strcpy(string2, argv[3]);
  length = strlen(string2);
  for(w=0;w<length; w++){
    string2[w] = tolower(string2[w]);
  }
  
  long valid1 = validCheck(string1); //check if strings are valid for program
  long valid2 = validCheck(string2);
  if(valid1 == 0 || valid2 == 0 ){
    fprintf(stderr, "ERROR invalid number in 1/2\n");
    return 0;
  }
  if(valid1 == 4 || valid2 == 4){
    fprintf(stderr, "ERROR: Number and number type do not match. \n");
    return 0;
  }  
  char *varNumSign;
  char typeChar1[8];
  char typeChar2[8];

  if(valid1==2 || valid1 == 5){ //num1 is negative, initailizing number 1 type and negativity
    varNumSign = "-";
      testNum1->type =  malloc (sizeof(char) *1);
    *testNum1->type = string1[1];
    strcpy(typeChar1, testNum1->type);
  }
  else{
    testNum1->type =  malloc (sizeof(char) *1); //num1 is not negative, initializing number 1 type
    *testNum1->type = string1[0];
    strcpy(typeChar1, testNum1->type);
  }
  if(valid2 == 2 || valid2 == 5){ //num2 is negative, initailizing number 1 type and negativity 
    varNumSign = "-";
     testNum2->type =  malloc (sizeof(char) *1);
    *testNum2->type = string2[1];
    strcpy(typeChar2, testNum2->type);
  }
  else{
    testNum2->type =  malloc (sizeof(char) *1);  //num2 is not negative, initializing number 2 type 
    *testNum2->type = string2[0];
    strcpy(typeChar2, testNum2->type);
  }
  if(strcmp(testNum1->type, "x") != 0 && (valid1 == 5 || valid1 == 3)){
    fprintf(stderr, "ERROR: Number and number type do not match. \n");
    return 0;
  }
  if(strcmp(testNum2->type, "x") != 0 && (valid2 == 5 || valid2 == 3)){
   fprintf(stderr, "ERROR: Number and number type do not match. \n");
    return 0;
  }

  long num1, num2, decimal1, decimal2;
  long dec1 = 0;
  long dec2 = 0;   
  if (valid1 == 3 || valid1 == 5 || (valid1==1 && strcmp(testNum1->type, "x")==0)){ //num1 is a Hex, makes hex string into long
    decimal1 = hexToDec(string1);
	if(valid1 == 5)
	decimal1 = -decimal1;
    dec1 = 1;
  }
  else{
    num1 = strToInt(string1); //puts others types as ints
                                                                                                                                                                            
}
  if(valid2 == 3 || valid2 == 5 || (valid2==1 && strcmp(testNum2->type, "x")==0)){
       decimal2 = hexToDec(string2); //num2 is hex made into an long dec
  if(valid2 == 5)
	decimal2 = -decimal2;
	 dec2 = 1;
     }
     else{
       num2 = strToInt(string2); 
             }  
  //char *hexNum = decToHex(num1);
  if(dec1 == 0){  //number is a converted hex already
    decimal1 = decConvert(num1, testNum1->type);
    }  
if(dec2 == 0){
  decimal2 = decConvert(num2, testNum2->type);
  }
  long op = strcmp(operation, "+");
  long decAnswer;
  long neg=2;
  if(op == 0){
  decAnswer = add(decimal1, decimal2);
  if(decAnswer <0){
    neg = 1;
    decAnswer = -decAnswer;
}
  }
  else if(strcmp(operation, "-") == 0)
{ 
printf ("dec1 -dec2 = %ld - %ld\n", decimal1, decimal2);
      decAnswer = subtract(decimal1, decimal2);
       if(decAnswer<0){
	 neg = 1;
	 decAnswer = -decAnswer;
       }
 }

   if(strcmp(operation, "*") == 0){
    decAnswer = multiply(decimal1, decimal2);
    if(decAnswer <0){
      neg = 1;
      decAnswer = -decAnswer;
    }
  }

 
  long finalAns;
  char *finHexAns;
   long retVal = strcmp(argv[4], "d");
    if(retVal == 0){
      if(neg == 1){
      printf("-d%ld\n", decAnswer);
      }
      else{
	printf("d%ld\n", decAnswer);
      }
    }
    if(strcmp(argv[4], "o") ==0){
      finalAns = decToOct(decAnswer);
      if(neg==1){
	printf("-o%ld\n", finalAns);
      }
      else{
      printf("ANSWER: o%ld\n", finalAns);
      }
    }
    if(strcmp(argv[4], "b")==0){
      finalAns = decToBin(decAnswer);
      if(neg == 1){
	printf("-b%ld\n", finalAns);
      }
      else{
      printf("b%ld\n", finalAns);
      }
    }
    if(strcmp(argv[4], "x")==0){
      finHexAns = decToHex(decAnswer);
      if(neg == 1){
	printf("-x%s\n", finHexAns);
	free(finHexAns);
      }
      else{
      printf("ANSWER: x%s\n", finHexAns);
      free(finHexAns);
      }
    }

 destroyMem(testNum1);
 destroyMem(testNum2);
free(string1);
free(string2);


return 0;

}


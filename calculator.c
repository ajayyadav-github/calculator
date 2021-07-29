#include <stdio.h>
#include<string.h>

int addsub();
int muldiv();
int evaluate();

char input[100];
int pos = 0;

int evaluate(){
  int number = 0;

  if(input[pos] == '('){
    pos++;
    number = addsub();
    
    if(input[pos] == ')'){
      pos++;
      return number;
    }
  }else{
    while('0' <= input[pos] && input[pos] <= '9'){
      number= number*10 + (input[pos] - '0');
      pos++;
    }
  }
  return number;
}

int muldiv(){
  int operand1,operand2;
  
  operand1 = evaluate();
  while(1){
    if(input[pos] == '*'){
      pos++;
      operand2 = evaluate();
      operand1 *= operand2; 
    }else if(input[pos] == '/'){
      pos++;
      operand2 = evaluate();
      operand1 /= operand2;
    }else{
      return operand1;
    }
  }
}

int addsub(){
  int operand1,operand2;
  
  operand1 = muldiv();
  
  while(1){
    if(input[pos] == '+'){
      pos++;
      operand2 = muldiv();
      operand1 += operand2; 
    }else if(input[pos] == '-'){
      pos++;
      operand2 = muldiv();
      operand1 -= operand2;
    }else{
      return operand1;
    }
  }
  
}

int main(){
  int number;
  scanf("%s",input);
  printf("%d",addsub());  
  return 0;
  }



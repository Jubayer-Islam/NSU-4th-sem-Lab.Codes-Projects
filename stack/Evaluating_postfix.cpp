#include <iostream>
#include "StackType.cpp"
#include <string.h>
#include<stdlib.h>

using namespace std;

//To Check the operators
int IsOperator(char value){
	if(value == '*' || value == '/' || value == '+' || value =='-'){
		return 1;
	}else{
        return 0;
	}
}

// To perform the operations
double Operation(double firstValue, double secondValue, char mathOperator){
	if(mathOperator == '+'){
		return firstValue+secondValue;
	}else if(mathOperator == '-'){
		return firstValue-secondValue;
	}else if(mathOperator == '*'){
		return firstValue*secondValue;
	}else if(mathOperator == '/'){
		return firstValue/secondValue;
	}else{
		return 0;
	}
}

int main(){

	StackType<double> obj1;
        double result;
        int counter;
        char postfix[100]
        for(counter = 0; postfix[counter] != '\0'; counter++){
            if(IsOperator(postfix[counter]) == 0){
                obj1.Push(postfix[counter] - '0');
            }else if(IsOperator(postfix[counter]) == 1){
                double x = obj1.Top();
                obj1.Pop();
                double y = obj1.Top();
                obj1.Pop();
                result = Operation(y, x, postfix[counter]);
                obj1.Push(result);
            }
        }
        cout << "\n\nResult is: " << result << endl;
    }
    return 0;
}
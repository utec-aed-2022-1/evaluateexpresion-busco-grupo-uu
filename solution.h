#include <iostream>
#include "double.h"
using namespace std;

struct Result{
    double result;
    bool error;
};


Result evaluate(string input)
{
    // 1- descomponer el input y validar

    // 2- convertir de Infijo a Postfijo
    
    // 3- resolver la expresion

    //* Si no cumple la validacion retornar Result.error = true;
    
    return Result();
}
template <typename T>
bool apilar(List<T>*& list, char data, List<char>*& result){
    bool correct = false; 
    string especial = "+-/*()";
    char poped; 
    if(data == especial[0] || data == especial[1]){
        while(true){
            if(list->back() == especial[4] || list->is_empty() == true){
                break; 
            } else list->precedencia(); 
        }
    } else if(data == especial[5]){
        while(true){
            if(list->back() == especial[4]) break; 
            else if(list->is_empty() == true) {return correct; break;}
            else {
                poped = list->pop_back(); 
                result->push_back(poped); 
            }
        }
    }
    list->push_back(data);
    return correct = true; 
}

template <typename T>
void add_last_operators(List<T>*& list, List<char>*& result, bool& correct){
    string especial = "()";
    char poped; 
    //poped = list->pop_back(); 
    //result->push_back(poped);
    int lenList = list->size();
    for(int i = 0; i < lenList; i++){
        poped = list->pop_back();
        if(poped == especial[0] || poped == especial[1])break;
        result->push_back(poped);
    }
    correct = true; 
}

void calculate(List<char>*& result){
    List<char> *stack_calculator = new DoubleList<char>();
    string especial = "+-/*";
    int a, b;
    double res = 0;  
    while(true){
        //if(result->front() != especial[0] && result->front() && especial[1] || result->front() && especial[2] && result->front() && especial[3]){
        if(result->front() != especial[0] && result->front() != especial[1] && result->front() != especial[2] && result->front() != especial[3]){
           stack_calculator->push_back(result->front()); 
        } else {
            a = stack_calculator->pop_back() - '0';
            b = stack_calculator->pop_back() - '0';
            if(result->front() == especial[0]) res = a+b; 
            else if(result->front() == especial[1]) res = a-b; 
            else if(result->front() == especial[2]) res = b/a;
            else if(result->front() == especial[3]) res = a*b;  
            string resS = to_string(res); 
            cout << "TERMINATOR: " << resS << " " << a << " " << result->front() << " " << b; 
            stack_calculator->push_back(resS[0]); 
        }
        result->pop_front();
        if(result->size() == 0)break; 
    }
    result = stack_calculator; 
}


bool check(string input){
    bool correct = false; 
    List<char> *operadores = new DoubleList<char>();
    List<char> *numeros = new DoubleList<char>();
    List<char> *resultado = new DoubleList<char>();
    string especial = " +-/*()";
    for (string::iterator it=input.begin(); it!=input.end(); ++it){
        if(*it != especial[0]){
            if(especial[1] == *it || especial[2] == *it || especial[3] == *it || especial[4] == *it || especial[5] == *it || especial[6] == *it)
            apilar<char>(operadores, *it, resultado); 
            else resultado->push_back(*it);
        }
    }
    if(operadores->is_empty() == false) add_last_operators(operadores, resultado, correct);
    //resultado->clear();
    calculate(resultado);
    //cout << resultado->front() << endl; 
    return correct; 
}
#include <iostream>
#include "double.h"
#include <string>
using namespace std;

struct Result{
    double result;
    bool error;
};


Result evaluate(string input)
{
    // 1- descomponer el input y validar (3+20)*(1+3)
    //bool err = check(input); 
    // double result = stoi(input); 54 string -> 54 double
    //Result.result = result;  54 
    //Result.error = err;  True o False
    // 2- convertir de Infijo a Postfijo
    
    // 3- resolver la expresion

    //* Si no cumple la validacion retornar Result.error = true;
    
    return Result();
}

//CONVERTIR DE INFIJO A POSTFIJO
template <typename T>
bool apilar(List<T>*& list, string data, List<string>*& result){
    bool correct = false; 
    string sum = "+";
    string rest = "-";
    string divi = "/";
    string mult = "*";
    string open = "(";
    string close = ")";
    string poped; 
    if(data == sum || data == rest || data == divi || data == mult){
        if(list->is_empty() != true){
            while(true){
                if(list->back() == open || list->is_empty() == true){
                    break; 
                } else {
                    if(data == divi || data == mult){
                        if(list->back() == sum || list->back() == rest){
                            break; 
                        }
                    }
                    poped = list->pop_back();
                    result->push_back(poped); 
                    if(list->is_empty() == true) break;
                }
            }
        }
    } else if(data == close){
        while(true){
            if(list->back() == open){
                list->pop_back();
                break;
            }
            else if(list->is_empty() == true) {return correct; break;}
            else {
                poped = list->pop_back(); 
                result->push_back(poped); 
            }
        }
    }
    if(data != close){
        list->push_back(data);
    }
    correct = true; 
    return correct; 
}
//ULTIMOS INFIJOS A POSTFIJOS
template <typename T>
void add_last_operators(List<T>*& list, List<string>*& result, bool& correct){
    string poped; 
    string open = "(";
    string close = ")";
    int lenList = list->size();
    for(int i = 0; i < lenList; i++){
        poped = list->pop_back();
        if(poped == open || poped == close){
            correct = false;  
            break;
        }else {
            correct = true; 
        };
        
        result->push_back(poped);
    }
}
//Resolver expresión
void calculate(List<string>*& result){
    List<string> *stack_calculator = new DoubleList<string>();
    string sum = "+";
    string rest = "-";
    string divi = "/";
    string mult = "*";
    double a, b;
    double res = 0;  
    while(true){
        if(result->front() != sum && result->front() != rest && result->front() != divi && result->front() != mult){
           stack_calculator->push_back(result->front()); 
        } else {
            a = stoi(stack_calculator->pop_back());
            b = stoi(stack_calculator->pop_back());
            if(result->front() == sum) res = a+b; 
            else if(result->front() == rest) res = a-b; 
            else if(result->front() == divi) res = b/a;
            else if(result->front() == mult) res = a*b;  
            string resS = to_string(res); 
            stack_calculator->push_back(resS); 
        }
        result->pop_front();
        if(result->size() == 0)break; 
    }
    result = stack_calculator; 
}

//Leer input
bool check(string& input){
    bool correct = true; 
    List<string> *operadores = new DoubleList<string>();
    List<string> *resultado = new DoubleList<string>();
    string especial = " +-/*()";
    string doubleData; 
    for (string::iterator it=input.begin(); it!=input.end(); ++it){
        if(*it != especial[0]){ 
            if(especial[1] == *it || especial[2] == *it || especial[3] == *it || especial[4] == *it || especial[5] == *it || especial[6] == *it){
                auto temp = it; 
                if(++temp == input.end()){
                    if(especial[1] == *it || especial[2] == *it || especial[3] == *it || especial[4] == *it){
                        return correct = false; 
                        break; 
                    }
                }
                if(doubleData.size() != 0){
                    resultado->push_back(doubleData);
                    doubleData = "";
                }
                doubleData.push_back(*it); 

                apilar<string>(operadores, doubleData, resultado); 
                doubleData = "";
            }else {
                doubleData.push_back(*it); 

                auto temp = it; 
                if(++temp == input.end()){
                    resultado->push_back(doubleData);
                    doubleData = "";
                }
                
            }
        }
    }
    if(operadores->is_empty() == false) add_last_operators(operadores, resultado, correct);
    if(correct==false) {
        input = "0"; 
        return correct;
    }
    calculate(resultado);
    input = resultado->front(); 
    cout << endl << "Resultado: " << input; 
    return correct; 
}
// Simple calculator for Addition, Subtraction, Multiplication and Division. 
#include <iostream>
using namespace std;

template <class T>
class calculator {
    T a, b;
    T last_result;
    bool is_first_operation;

public:
    calculator() : last_result(0), is_first_operation(true) {}
    //Function for  getting data from user
    void get_data() {    
        //If getting data for first time                               
        if (is_first_operation) {
            cout << "Enter first number: ";           
            cin >> a;
            is_first_operation = false;
        } 
         //Want to apply operation on last result
        else {
            a = last_result;
            cout << "Previous result: " << a << endl;     
        }
        //Taking second number from user
        cout << "Enter second number: ";                 
        cin >> b;
    }
    //Fuction for addtion
    T add() {                                              
        last_result = a + b;
        return last_result;
    }
     //Fuction for subtraction
    T sub() {                                             
        last_result = a - b;
        return last_result;
    }
    //Fuction for multiplication
    T mul() {                                              
        last_result = a * b;
        return last_result;
    }
    //Fuction for division
    T div() {                                              
        if (b != 0) {
            last_result = a / b;
            return last_result;
        }
        //Throw exception division by zero 
        else {
            throw runtime_error("Division by zero error!");          
        }
    }
    //To start a new calculation
    void clear() {                                          
        last_result = 0;
        is_first_operation = true;
        cout << "Calculator cleared...... Starting a new calculation......" << endl;
    }
};

int main() {
    try {
        bool continue_counting = true;
        calculator<double> c1;
        // To chose operation continuously until continue_counting is true
            int operation;
        while (continue_counting) {                                 
            cout << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=" << endl;
            cout << "Menu" << endl;
            cout << "=======================================================================" << endl;
            cout << "Enter 1 for Addition \nEnter 2 for Subtraction \nEnter 3 for Multiplication \nEnter 4 for Division \nEnter 5 to Clear \nEnter 6 to Exit" << endl;
            cout << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=" << endl;
            cout << "Enter the value: ";
            cin >> operation;

            switch (operation) {
                case 1:
                    c1.get_data();
                    cout << "Result: " << c1.add() << endl;         //To add the values
                    break;
                case 2:
                    c1.get_data();
                    cout << "Result: " << c1.sub() << endl;         // To subtract the values
                    break;
                case 3:
                    c1.get_data();
                    cout << "Result: " << c1.mul() << endl;         // To multiply the values
                    break;
                case 4:
                    c1.get_data();
                    cout << "Result: " << c1.div() << endl;         // To divide the values
                    break;
                case 5:
                    c1.clear();         // Clear the calculator and start a new calculation
                    break;
                case 6:
                    continue_counting = false;                      // To exit the loop
                    break;
                default:
                    cout << "Invalid operation" << endl;            // For wrong choice
            }
        }
    }
    // Catch block for division by zero 
    catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
    
    return 0;
}
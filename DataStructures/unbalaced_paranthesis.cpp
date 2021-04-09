#include "stacks_using_ll.cpp"

int main(int argv, char *argc[])
{
    Stack<char> expression;
    cout<< "Input Expression: " << argc[1] <<endl;

    int i = 0;
    char elem;
    while(argc[1][i] != '\0'){
        elem = argc[1][i++];
        if( (elem == '{') || (elem == '[') || (elem == '(') ) {
            expression.push(elem);
        }
        else if(elem == '}'){
            if (expression.top() == '{')
                expression.pop();
            else {
                cout<<"Expression is unbalanced" << endl;
                return 0;
            }
        }
        else if(elem == ']'){
            if (expression.top() == '[')
                expression.pop();
            else {
                cout<<"Expression is unbalanced" << endl;
                return 0;
            }
        }
        else if(elem == ')'){
            if (expression.top() == '(')
                expression.pop();
            else {
                cout<<"Expression is unbalanced" << endl;
                return 0;
            }
        }
           
           
    } 
    if(expression.getsize() != 0) {
        
        cout<<"Expression is unbalanced" << endl;
    } else 
        cout <<"Balanced Expression" << endl;

}

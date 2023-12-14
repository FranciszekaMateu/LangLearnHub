#include <iostream>
#include <string>
#include <set>
#include <stdexcept>

using namespace std;

string numToString(set<string> lst)
{
    set<string>::iterator iter;
    int contador = 1;
    for (iter = lst.begin(); iter != lst.end(); ++iter)
    {
        cout << "[" << contador << "] " << *iter << "" << endl;
        ++contador;
    }
    cout << "[" << contador << "] "
         << "Salir" << endl;

    string input;
    int choice = 0;

    while (true)
    {
        getline(cin, input);
        try
        {
            choice = stoi(input);
            if (choice == contador)
            {
                return "salir";
            }
            else if (choice > 0 && choice <= lst.size())
            {
                iter = lst.begin();
                advance(iter, choice - 1);
                return *iter;
            }
            else
            {
                cout << "Error, selecciona un número de la lista" << endl;
            }
        }
        catch (const std::invalid_argument &e)
        {
            cout << "Error, por favor introduce un número" << endl;
        }
        catch (const std::out_of_range &e)
        {
            cout << "Error, el número es demasiado grande" << endl;
        }
    }
}
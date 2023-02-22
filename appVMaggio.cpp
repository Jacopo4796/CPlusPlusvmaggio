/*
- Scrivere un programma che rimane aperto
  finché l'utente non digita "exit".
- Il programma chiede all'utente una parola
  da cercare nel 5 Maggio.
- Restituisce a schermo: i versetti con i numeri di
  riga in cui appare la parola cercata.
- Chiede la successiva parola a meno che non si
  inserisce EXIT.
  */

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    string riga;
    string parola;
    int numeroRigaParolaTrovata = 0;

    while (parola != "exit")
    {
        cout << "Inserisci la parola che vuoi trovare. \n";
        cin >> parola;

        ifstream fileInput("maggio.txt");

        while (getline(fileInput, riga))
        {
            numeroRigaParolaTrovata++;
            bool flag = false; // SE TROVO LA PAROLA IMPOSTO A TRUE

            for (int i = 0; i < riga.length(); i++) // for tutta riga
            {
                for (int j = 0; j < parola.length(); j++) // for tutta parola
                {
                    if (riga[i] == parola[j]) // se le lettere sono uguali
                    {
                        if (j == parola.length() - 1) // se le lettere sono uguali e sono all'ultima lettera della parola
                        {
                            flag = true; // PAROLA TROVATA
                        }
                        i++;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if (flag == true)
            {
                cout << "La parola si trova alla riga: " << numeroRigaParolaTrovata << "\n";
            }
        }
        fileInput.close();
    }
}
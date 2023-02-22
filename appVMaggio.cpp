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
    string versetti;
    int numeroVerso = 0;

    while (parola != "exit") // WHILE la parola è diversa da "exit"
    {
        cout << "Inserisci la parola che vuoi trovare. \n";
        cin >> parola;
        ifstream fileInput("maggio.txt");
        versetti = "";
        numeroVerso = 0;

        while (getline(fileInput, riga)) // Leggi tutte le righe
        {
            numeroVerso++;

            if (riga != "")
            {
                versetti += to_string(numeroVerso) + " - " + riga + "\n";
            }
            else
            {
                versetti = "";
            }

            bool trovata = false; // SE TROVO LA PAROLA IMPOSTO A TRUE

            for (int i = 0; i < riga.length(); i++) // FOR tutta riga
            {
                for (int j = 0; j < parola.length(); j++) // FOR tutta parola
                {
                    if (riga[i] == parola[j]) // IF le lettere sono uguali
                    {
                        if (j == parola.length() -1 ) // IF le lettere sono uguali e sono all'ultima lettera della parola
                        {
                            trovata = true; // PAROLA TROVATA
                            cout << "La parola si trova al verso: " << numeroVerso << "\n";

                            while (getline(fileInput, riga))
                            {
                                numeroVerso++;

                                if (riga == "")
                                {
                                    break;
                                }
                                else
                                {
                                    versetti += to_string(numeroVerso) + " - " + riga + "\n";
                                }
                            }
                            cout << versetti << "\n";
                        }
                        i++;
                    }
                    else
                    {
                        break; // Smette di controllare
                    }
                }
            }
        }
        fileInput.close();
    }
}
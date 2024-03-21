#include <iostream>
#include <fstream>
#include <iomanip>

int main()
{
    std::string nameFile = "data.csv"; // memorizzo il nome del file
    std::ifstream fstr; // fstr mi serve per leggere i dati da file
    fstr.open(nameFile); // apro il file passando per fstr

    if(fstr.fail()) //controllo se il file è stato aperto correttamente
    {
        std::cerr << "File not found" <<std::endl;
        return 1;
    }
    std::string outputNameFile = "result.csv"; //memorizzo il nome del file di output
    std::ofstream output(outputNameFile); //apro il file di output

    if(output.fail()) //controllo se il file di output è stato aperto correttamente
    {
        std::cerr << "Error opening the file" <<std::endl;
        return 1;
    }

    output << "# N mean" << "\n" << std::endl; //scrivo l'intestazione
    int index = 0; //inizializzo l'indice a 0
    double sum = 0; //inizializzo la somma a 0
    double val; //dichiaro il tipo di valore che devo leggere nel file
    while(fstr >> val)
    {
        double mappedValue = ((3./4.)*val)-(7./4.);  // mappo il nuovo valore che leggo nel nuovo intervallo
        sum += mappedValue; //sommo il valore mappato ai precedenti vlori mappati
        double mean = sum/++index; //calcolo la media dei valori fino ad adesso mappati aggiornando l'indice
        output << index<< " " << std::scientific << std::setprecision(16) << mean << "\n" << std::endl; //stampo la media

    }
    fstr.close(); // chiudo il file in lettura
    output.close(); // chiudo il fle in scrittura
    return 0;
}

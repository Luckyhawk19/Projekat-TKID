#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// funkcija koriscena zbog bolje raspodeljenosti u odnosu na kalkulisanje sa modulom
int nasumicni_broj(int min, int max)
{
    static double x { 1.0 / (RAND_MAX + 1.0) };
    return min + static_cast<int>((max - min + 1) * (rand() * x));
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    string unos;
    getline(cin >> ws, unos);

    string kodiraniTekst("");
    for (int i = 0; i < unos.size(); ++i)
    {
        string dodatak("");
        dodatak.resize(8);

        int x = nasumicni_broj(1, 7);
        dodatak[x] = unos[i] + 17;
        dodatak[x-1] = 'a';

        for (int j = 0; j < 8; ++j)
        {
            if ((j != x) && (j != (x-1)))
            {
                dodatak[j] = static_cast<char>(nasumicni_broj(32, 127));
                if (dodatak[j] == 'a') dodatak[j] += static_cast<char>(nasumicni_broj(1, 25));
            }
        }
        kodiraniTekst += dodatak;
    }

    cout << kodiraniTekst;
    return 0;
}

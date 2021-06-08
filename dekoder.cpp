#include <iostream>
#include <string>

using namespace std;

int main()
{
    string kodirani_tekst;
    getline(cin, kodirani_tekst);

    string trazeni_tekst("");
    for (int i = 0; i < kodirani_tekst.size(); ++i)
        if (kodirani_tekst[i] == 'a')
        {
            trazeni_tekst.push_back(kodirani_tekst[i+1]-17);
            i += (8 - (i - (i/8)*8)) - 1;

        }

    cout << trazeni_tekst;

    return 0;
}

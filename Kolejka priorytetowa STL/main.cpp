#include <iostream>
#include <queue>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));
    string imiona[5]= {"Jan","Adam","Marek","Marian","Tymon"};
    string nazwiska[5]= {"Kowalski","Nowak","Kalinowski","Rybak","Halicki"};


    class osoba
    {
        int nr=0;
        string imie="";
        string nazwisko="";

    public:

        osoba(int nr, string imie, string nazwisko)
        {
            this->nr=nr;
            this->imie=imie;
            this->nazwisko=nazwisko;
        };


        void wysw()
        {
            cout << nr << " "<< imie << " "<<nazwisko<<endl;
        }

        void zmiendane(int nr, string imie, string nazwisko)
        {
            this->nr=nr;
            this->imie=imie;
            this->nazwisko=nazwisko;
        }

        bool operator<(const osoba &o) const
        {
            return nr<o.nr;
        }

        bool operator=(const osoba &o)
        {
            nr=o.nr;
            imie=o.imie;
            nazwisko=o.nazwisko;
        }

    };



    std::priority_queue<osoba> *a=new std::priority_queue<osoba>;
    // std::queue<osoba> *a=new std::queue<osoba>;

    osoba o(0,"","");
    osoba o1(1, "Jan", "Kowalski");

    for(int i=0; i<20; i++)
    {
        o1.zmiendane(rand()%1000, imiona[rand()%5], nazwiska[rand()%5]);
        a->push(o1);
    }


    while(!a->empty())
    {
        o=a->top();
        //o=a->front();
        a->pop();
        o.wysw();
    }


    delete a;

    return 0;
}

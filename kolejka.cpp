#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define MAX 10 // maksymalna długość kolejki


class Queue
{
    private:
    int kolejka[MAX];
    int front, back;

    public:

    //ustawiamy zmienne swiadczace ze kolejka jest pusta
    Queue()
    {
        front = -1;
        back = -1;
    }

    //sprawdzamy czy kolejka jest pusta
    bool IsEmpty()
    {
        return (front == -1 && back == -1);
    }

    //sprawdzamy czy kolejka jest pelna
    bool IsFull()
    {
        return (back+1)%MAX == front ? true : false;
    }

    //funkcja ma za zadanie dodac nowa zawartosc do kolejki
    void push(int x)
    {
        cout<<"Przyszedl nowy klient \n";
        if(IsFull())
        {
            cout<<"ale kolejka była pelna i wyszedl \n";
            return;
        }
        if (IsEmpty())
        {
            front = back = 0;
        }
        else
        {
            back=(back+1)%MAX;
        }
        kolejka[back]=x;
    }

    //funkcja zmienia pierwsza wartosc w kolejce
    void pop()
    {
        if(IsEmpty())
        {
            cout<<"Kolejka jest pusta\n";
            return;
        }
        else if(front == back)
        {
            back = front = -1;
        }
        else
        {
            front = (front+1)%MAX;
        }
    }

    //funkcja zwraca pierwsza wartosc w kolejce
    int Front()
    {
        if(IsEmpty())
        {
            cout<<"Kolejka jest pusta\n";
            return -1;
        }
        return kolejka[front];
    }

    //funkcja wypisuje wszystkie wartosci dostepne w kolejce
    void Print()
    {
        if(IsEmpty())
        {
            cout<<"Kolejka jest pusta\n";
            return;
        }
        int ile = (back + MAX - front)%MAX +1;
        cout<<"W kolejce są:   ";
        for(int i=0; i<ile; i++)
        {
            int index = (front+i) % MAX;
            cout<<kolejka[index]<<", ";
        }
        cout<<"\n\n";
    }

    //funkcja zwraca ilosc wartosci w kolejce
    int ile()
    {
        return ((back + MAX - front)%MAX +1);
    }
};

int main()
{
    Queue Q;    //wywolujemy kolejke do zycia
    int wybor;  //zmienna potrzebna do menu

    srand( time (NULL));    

    Q.push((rand()%9+1));   //dodajemy do kolejki przykladowe wartosci
    Q.push((rand()%9+1));
    Q.push((rand()%9+1));


    while(wybor != 0)
    {
        if((rand()%20)<10)  //losujemy liczbe od 0 do 19 i jesli jest ona mniejsza od 10 dodajemy nowa wartosc do kolejki
        {
            Q.push((rand()%9+1));
        }

        cout << "\nW kolejce obecnie czeka " << Q.ile() <<" osob\n\n";  //wypisujemy ilosc wartosci w kolejce

        cout << "1 - Pobierz informacje o kliencie\n";
        cout << "2 - Wypisz wszystkie dane z kolejki\n";
        cout << "0 - Wylacz program\n";

        cout <<"Twoj wybor: ";
        cin >> wybor;
        cout<<"\n";

        switch(wybor)
        {
            case 1:
            cout<< "Informacja o kliencie:" << Q.Front() << "\n";
            Q.pop();
            break;
            case 2:
                Q.Print();
            break;
            case 0:
            cout << "Koniec programu\n";
            break;
        }
    }

    return 0;
}
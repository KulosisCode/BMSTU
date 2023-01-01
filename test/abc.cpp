#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

struct TS 
{
    char ht[20];
    long sobd;
    float td;
};

int main(void)
{
    TS *ts;
    int n;
    cout <<"\n So thi sinh n = ";
    cin >> n;
    ts = new TS[n+1];
    if (ts == NULL)
    {
        cout << "LOI CAP PHAT!";
        getch();
        exit(0);
    }

    for (int i = 1; i <= n; i++)
    {
        cout <<"Thi sinh thu " << i;
        cout <<"\nHo ten : ";
        cin.ignore(1);
        cin.get(ts[i].ht, 20);

        cout << "So bao danh: ";
        cin >> ts[i].sobd;
        cout << "Tong diem: ";
        cin >> ts[i].td;

    }

    cout << setiosflags(ios::showpoint) << setprecision(1);
    for (int i = 1; i <= n; i++)
    {
        cout << "\n" << setw(20) << ts[i].ht << setw(6) << ts[i].sobd << setw(6) << ts[i].td;
        // cout << "\n" << ts[i].ht << ts[i].sobd << ts[i].td;
    }

    delete ts;
    getch();
    return 0;
}

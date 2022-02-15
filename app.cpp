#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std;

fstream create;
string choise;
int info = 0;
int selection;
int rentDays;

class Car {
public:
    float CostPerDay;
    float courseCost;
    string manufacturer;
    string model;
    int productionYear;
    int mileage;
};

Car miata;
Car supra;

void createFile() {
    create.open("vehicles.txt", ios::out);
    create << "Mazda\n";
    create << "MX-5\n";
    create << "1998\n";
    create << "87344\n";
    create << "Toyota\n";
    create << "Supra\n";
    create << "1997\n";
    create << "12215";
    create.close();
}
void readFile() {
    create.open("vehicles.txt", ios::in);
    create >> miata.manufacturer;
    create >> miata.model;
    create >> miata.productionYear;
    create >> miata.mileage;
    create >> supra.manufacturer;
    create >> supra.model;
    create >> supra.productionYear;
    create >> supra.mileage;
    create.close();
}
void calculateCost() {
    switch(selection) {
        case 1:
            cout << "Dobrze, wypozyczamy Mazde MX-5. Jej koszt na dobe wynosi 200 zlotych, a oplata poczatkowa to 100 zlotych. Na ile dob chcesz ja wypozyczyc?\n";
            cin >> rentDays;
            miata.CostPerDay = 200;
            cout << "Czy na pewno chcesz wypozyczyc ten samochod?\n";
            cin >> choise;
                if (choise == "tak") {
                    cout << "Dobrze, obliczam opłate...\n";
                    miata.courseCost = rentDays * miata.CostPerDay;
                    miata.courseCost = miata.courseCost + 100;
                    Sleep(800);
                    cout << "Oplata za wypozyczenie wynosi " << miata.courseCost << " zlotych. Po " << rentDays << " dniach zglos sie do nas, by oddac samochod.\n";
                    Sleep(5000);
                    break;
                }
                else {
                    cout << "Szkoda, mamy nadzieje, ze skorzystasz kiedys z naszych uslug.";
                    Sleep(5000);
                    break;
                }
        case 2:
            cout << "Wiec wypozyczamy Toyote Supre. Oplata na start to 150 zlotych, a cena za dobe to 250 zlotych. Na ile dob chcesz wypozyczyc ten samochod?\n";
            cin >> rentDays;
            supra.CostPerDay = 250;
            cout << "Jestes pewien, ze chcesz wypozyczyc supre?\n";
            cin >> choise;
                if (choise == "tak") {
                    cout << "Obliczam cene, poczekaj chwile...\n";
                    supra.courseCost = rentDays * supra.CostPerDay;
                    supra.courseCost = supra.courseCost + 250;
                    Sleep(800);
                    cout << "Oplata za wypozyczenie wynosi " << supra.courseCost << " zlotych. Po uplywie " << rentDays << " dni zglos sie do nas, by oddac samochod.\nNasza wypozyczalia jest przy ulicy Kosciuszki 33 w Rzasni.\n";
                    Sleep(5000);
                    break;
                }
                else {
                    cout << "W takim razie zapraszamy ponownie.";
                    Sleep(5000);
                    break;
                }
        default:
            cout << "Wybierz samochod!";
            calculateCost();
    }
    }
int main() {
    createFile();
    readFile();
    cout << "Witamy w naszej wypozyczalni, samochody w naszej flocie to:\n";
    cout << "1) "<< miata.manufacturer << " " << miata.model << " z " << miata.productionYear << " roku.\n";
    cout << "2) "<< supra.manufacturer << " " << supra.model << " z " << supra.productionYear << " roku.\n";
    cout << "Jezeli chcesz wypozyczyc ktorys z nich, wpisz jego numer.\n";
    cin >> selection;
    calculateCost();
    return 0;
}
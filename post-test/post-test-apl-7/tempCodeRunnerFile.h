#ifndef UI_H
#define UI_H

#include <iostream>
#include <cstdlib>
using namespace std;

void clear(){
    system("cls"); // Linux/Mac: system("clear");
}

void garis(){
    cout<<"========================================\n";
}

void header(string judul){
    garis();
    cout<<"        "<<judul<<endl;
    garis();
}

#endif
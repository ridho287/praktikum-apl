#ifndef UI_H
#define UI_H

#include <iostream>
#include <cstdlib>
using namespace std;

void clear(){
    system("cls");
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
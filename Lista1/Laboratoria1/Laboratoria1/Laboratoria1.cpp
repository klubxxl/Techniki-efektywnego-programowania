#include <iostream>
#include "CTable.h"

// ZADANIE 1
void v_alloc_table_add_5(int iSize) {
    if (iSize < 0) {
        std::cout << "Rozmiar tablicy nie moze byc ujemny";
    } else {
        int* table;
        table = new int[iSize];

        for (int i = 0; i < iSize; i++)
            table[i] = i + 5;

        for (int i = 0; i < iSize; i++)
            std::cout << table[i] << std::endl;

        delete[] table;
    }
}

// ZADANIE 2
bool b_alloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY) {
    if (iSizeX < 0 || iSizeY < 0) {
        return false;
    }
    else {
        *piTable = new int* [iSizeX];

        for (int i = 0; i < iSizeX; i++)
            (*piTable)[i] = new int[iSizeY];

        return true;
    }
}

// ZADANIE 3
bool b_dealloc_table_2_dim(int** piTable, int iSizeX, int iSizeY) {
    if (iSizeX < 0 || iSizeY < 0) {
        return false;
    }
    else {
        for (int i = 0; i < iSizeX; i++)
            delete piTable[i];

        delete[] piTable;

        return true;
    }
}

// ZADANIE 4

void v_mod_tab(CTable* pcTab, int iNewSize) {   // ZMIENIA W NASZYM CTable
    pcTab->bSetNewSize(iNewSize);
}
void v_mod_tab(CTable cTab, int iNewSize) {     // NIE ZMIENIA
    cTab.bSetNewSize(iNewSize);
}

int main()
{
    v_alloc_table_add_5(10);

    int** pi_table;
    std::cout << b_alloc_table_2_dim(&pi_table, 5, 3) << std::endl;
    std::cout << b_dealloc_table_2_dim(pi_table, 5, 3) << std::endl;

    CTable cTable("test", 5);
    cTable.getInfo();
    cTable.vSetName("test_n");
    cTable.bSetNewSize(8);
    cTable.getInfo();
    //v_mod_tab(cTable, 10);
    //cTable.getInfo();
    v_mod_tab(&cTable, 12);
    cTable.getInfo();

    CTable cTable2("test2", 4);
    cTable.Merge(&cTable2);
}
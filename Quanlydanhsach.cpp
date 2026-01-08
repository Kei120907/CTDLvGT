

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct Becon {
    char tenbe[50];
    char ms[7];
    int tuoi;
    float cao, nang;
};


void NhapHS(Becon& bc) {
    do {
        cout << "\n Nhap ma so be (xxx): ";
        cin >> bc.ms;
    } while (strlen(bc.ms) != 3);
    cin.ignore();
    cout << "\n Nhap ho ten: ";
    cin.getline(bc.tenbe, 50);
    cout << "\n Tuoi: ";
    cin >> bc.tuoi;
    cout << "\n Chieu cao (cm): ";
    cin >> bc.cao;
    cout << "\n Can nang (kg): ";
    cin >> bc.nang;
}

void NhapLop(Becon lop[], int &n) {
    cout << "\n Nhap so be hoc tai truong man non Hoa Hong: ";
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        cout << "\n Hoc sinh thu " << i + 1;
        NhapHS(lop[i]);
        cin.ignore();
    }
}

void InHS(Becon bc) {
    cout << "\n    Ma so be: " << bc.ms;
    cout << "\n    Ten be: " << bc.tenbe;
    cout << "\n    Tuoi: " << bc.tuoi;
    cout << "\n    Chieu cao (cm): " << bc.cao;
    cout << "\n    Can nang (kg): " << bc.nang;
}

void InLop(Becon lop[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout << "\n Hoc sinh thu " << i + 1;
        InHS(lop[i]);
    }
}

void TKTT(Becon lop[], int n, char x[]) {
    cout << "\nNhap ma so can tim: "; cin >> x;
    int t = -1;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(x, lop[i].ms) == 0) {
            t = i; break;
        }
    }
    if (t != -1) {
        cout << "Tim thay ma so, Thong tin be: "; InHS(lop[t]);
    }
    else cout << "Ko tim thay";
}

float BMI(Becon bc) {
    return bc.nang / ((bc.cao * bc.cao) / 10000);
}

void BMImax(Becon lop[], int n) {
    int vt = 0;
    float M = BMI(lop[0]);
    for (int i = 1; i < n; i++) {
        if( BMI(lop[i]) > M) {
            vt = i; M = BMI(lop[i]);
        }
    }
    cout << "\n Be co BMI lon nhat: ";
    InHS(lop[vt]);
}

void Auto(Becon lop[], int& n) {
    n = 3;
    lop[0] = { "Vo Hoang Huy","001",5,167,50 };
    lop[1] = { "Pham Ngoc Minh Man","002",5,165,48 };
    lop[2] = { "Vo Pham Ngoc Long","003",5, 169,55};
    InLop(lop, n);
}

void Bosung(Becon lop[], int& n) {
    int a;
    cout << "\n Nhap so hs can bo sung vao danh sach: "; cin >> a;
    for (int i = n; i < n+a; i++)
    {
        cout << "\n Hoc sinh thu " << i + 1;
        NhapHS(lop[i]);
        cin.ignore();
    }
    n = n + a;
}
void DS(Becon lop[], int& n, int&tt) {
    int lc1;
    do {
        cout << "\n ===========================";
        cout << "\n Nhap '1': Auto danh sach hs";
        cout << "\n Nhap '2': Nhap danh sach hs";
        cout << "\n Nhap '3': Bo sung danh sach hs";
        cout << "\n Nhap '4': Ket thuc buoc chinh sua danh sach, den buoc tiep theo";
        cout << "\n Nhap lua chon cua ban: ";
        cin >> lc1;
        cin.ignore(); tt++;
        switch (lc1) {
        case 1: Auto(lop, n); break;
        case 2: NhapLop(lop, n); break;
        case 3: Bosung(lop, n); break;
        case 4: cout << "Da hoan tat chinh sua danh sach!\n"; break;
        default: cout << "Lua chon khong hop le!\n";
        }
    } while (lc1 != 4);
}
int main() {
    char x[7];
    int t, lc2, tt = 1;
    Becon lop[30];
    DS(lop,t,tt);
    do {
        cout << "\n ---------MENU---------";
        cout << "\n Nhap '-1': Quay tro lai thao tac chinh sua danh sach";
        cout << "\n Nhap '0': In danh sach be tai truong man non Hoa Hong";
        cout << "\n Nhap '1': Tim kiem thong tin be theo ms";
        cout << "\n Nhap '2': Tim be co BMI lon nhat";
        cout << "\n Nhap '3': Ket thuc chuong trinh";
        cout << "\n Nhap lua chon cua ban: ";
        cin >> lc2; cin.ignore(); tt++;
        switch (lc2) {
        case -1:DS(lop,t,tt); break;
        case 0: InLop(lop, t); break;
        case 1: TKTT(lop, t, x); break;
        case 2: BMImax(lop, t); break;
        case 3: cout << "\n ---Chuong trinh da duoc ket thuc, so thao tac= "<<tt<<"---"; break;
        }
 
    } while (lc2 != 3);
}

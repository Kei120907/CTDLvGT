#include <iomanip>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

struct Becon {
    string tenbe;
    string ms;
    int tuoi;
    float cao, nang;
};


void NhapHS(Becon& bc) {
    do {
        cout << "\n Nhap ma so be (xxx): ";
        getline(cin, bc.ms);
    } while (0 >= (bc.ms).length() || (bc.ms).length() > 3);
    do {
        cout << "\n Nhap ho ten be, toi da 31 ky tu (khong duoc de trong): ";
        getline(cin, bc.tenbe);
    } while (0 >= (bc.tenbe).length() || (bc.tenbe).length() > 31);
    do {
        cout << "\n Tuoi (lon hon 0): ";
        cin >> bc.tuoi;
    } while (bc.tuoi <= 0);
    do {
        cout << "\n Chieu cao (cm,>0): ";
        cin >> bc.cao;
    } while (bc.cao <= 0);
    do {
        cout << "\n Can nang (kg,>0): ";
        cin >> bc.nang;
    } while (bc.nang <= 0);
}

void NhapLop(Becon lop[], int& n) {
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
    cout << setw(14) << left << bc.ms
        << setw(25) << left << bc.tenbe
        << setw(8) << bc.tuoi
        << setw(17) << bc.cao
        << setw(17) << bc.nang << endl;
}

void InLop(Becon lop[], int n) {
    if (n == 0) cout << "\n Danh sach trong";
    else {
        cout << setw(14) << left << "Ma so be "
            << setw(25) << left << "Ho ten be"
            << setw(8) << "Tuoi"
            << setw(17) << "Chieu cao(cm)"
            << setw(17) << "Can nang(kg)" << endl;
        for (int i = 0; i < n; i++)
        {
            //cout << "\n Hoc sinh thu " << i + 1;
            InHS(lop[i]);
        }
    }
}

void TKTT(Becon lop[], int n) {
    string x;
    cout << "\nNhap ma so can tim: ";  getline(cin, x);
    int t = -1;
    for (int i = 0; i < n; i++)
    {
        if (x == lop[i].ms) {
            t = i; break;
        }
    }
    if (t != -1) {
        cout << "Tim thay ma so, Thong tin be: \n";  cout << setw(14) << left << "Ma so be "
            << setw(25) << left << "Ho ten be"
            << setw(8) << "Tuoi"
            << setw(17) << "Chieu cao(cm)"
            << setw(17) << "Can nang(kg)" << endl; InHS(lop[t]);
    }
    else cout << "Ko tim thay";
}

void TKTTcolc(Becon lop[], int n) {
    string x;
    cout << "\nNhap ma so can tim: "; getline(cin, x);
    int t = 0;
    lop[n].ms = x;
    while (lop[t].ms != x) {
        t++;
    }
    if (t < n) {
        cout << "Tim thay ma so, Thong tin be: \n";  
        cout << setw(14) << left << "Ma so be "
            << setw(25) << left << "Ho ten be"
            << setw(8) << "Tuoi"
            << setw(17) << "Chieu cao(cm)"
            << setw(17) << "Can nang(kg)" << endl; InHS(lop[t]);
    }
    else cout << "Ko tim thay";
}

void LCSX(Becon lop[], int n, int& tt, int& sx);


void TKNP(Becon lop[], int n, int tt, int sx) {
    if (sx == 0) {
        cout << "\n Ham cua ban chua duoc sap xep, mo menu Sap xep";
        LCSX(lop, n, tt, sx);
    }
    int l = 0, r = n - 1;
    string x;
    do {
        cout << "\n Nhap ma hoc sinh can tim (dang xxx): ";
        getline(cin, x);
    } while (x.length() != 3);

    while (l <= r) {
        int m = (l + r) / 2;
        if (lop[m].ms == x) {
            cout << "Tim thay ma so, thong tin: \n";
            cout << setw(14) << left << "Ma so be "
                << setw(25) << left << "Ho ten be"
                << setw(8) << "Tuoi"
                << setw(17) << "Chieu cao(cm)"
                << setw(17) << "Can nang(kg)" << endl;
            InHS(lop[m]);
            return;
        }
        if (lop[m].ms > x) r = m - 1;
        else l = m + 1;
    }
    cout << "Khong tim thay";
}
float BMI(Becon bc) {
    return bc.nang / ((bc.cao * bc.cao) / 10000);
}

void BMImaxmin(Becon lop[], int n) {
    int vtmax=0, vtmin = 0;
    for (int i = 1; i < n; i++) {
        if (BMI(lop[i]) > BMI(lop[vtmax])) {
            vtmax = i;
        }
        else vtmin = i;
    }
    cout << "\nBMI max= " << BMI(lop[vtmax])<<",thong tin be:"<<endl;
    cout << setw(14) << left << "Ma so be "
        << setw(25) << left << "Ho ten be"
        << setw(8) << "Tuoi"
        << setw(17) << "Chieu cao(cm)"
        << setw(17) << "Can nang(kg)" << endl;
    InHS(lop[vtmax]);
    cout << "\nBMI min= " << BMI(lop[vtmin]) << ",thong tin be:" << endl;
    cout << setw(14) << left << "Ma so be "
        << setw(25) << left << "Ho ten be"
        << setw(8) << "Tuoi"
        << setw(17) << "Chieu cao(cm)"
        << setw(17) << "Can nang(kg)" << endl;
    InHS(lop[vtmin]);
    cout << endl;
    cout << "Chenh lech BMI thap nhat va cao nhat= " << BMI(lop[vtmax]) - BMI(lop[vtmin]);
}
void Thongke(Becon lop[], int n) {
    float tbbmi = 0;
    for (int i = 0; i < n; i++) {
        tbbmi += BMI(lop[i]);
    }
    tbbmi = tbbmi / n;
    cout << "BMI trung binh=" << tbbmi << endl << endl;
    cout << "Ma so hoc sinh co BMI thap hon trung binh: ";
    for (int i = 0; i < n; i++) {
        if (BMI(lop[i]) < tbbmi) cout << lop[i].ms<<"    ";
    }    cout << endl << endl;

    cout << "Ma so hoc sinh co BMI cao hon trung binh: ";
    for (int i = 0; i < n; i++) {
        if (BMI(lop[i]) > tbbmi) cout << lop[i].ms << "    ";
    }    cout << endl;
    BMImaxmin(lop, n);
}
void Auto(Becon lop[], int& n) {
    n = 8;
    lop[0] = { "Vo Hoang Huy","005",5,167,50 };
    lop[1] = { "Pham Ngoc Minh Man","003",5,165,48 };
    lop[2] = { "Vo Pham Ngoc Long","001",7, 169,55 };
    lop[3] = { "Vo Pham Hoang Long","002",5, 167,60 };
    lop[4] = { "Vo Pham Minh Long","004",6, 166,58 };
    lop[7] = { "Vo Pham Ngoc Diep","007",7,164,49 };
    lop[6] = { "Vo Pham Tuong Vy","008",6,164,48 };
    lop[5] = { "Vo Pham Bao Ngoc","010",5, 170,55 };
    InLop(lop, n);
}
void swap(Becon& a, Becon& b) {
    Becon temp = a;
    a = b;
    b = temp;
}
void Selectionsort(Becon lop[], int n) {
    int min;
    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++)
            if (lop[j].ms < lop[min].ms) min = j;
        swap(lop[min], lop[i]);
    }
}
void Interchangesort(Becon lop[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (lop[i].ms > lop[j].ms) {
                swap(lop[i], lop[j]);
            }
        }
    }
}
void Bubblesort(Becon lop[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            if (lop[j - 1].ms > lop[j].ms) {
                swap(lop[j], lop[j - 1]);
            }
        }
    }
}

void BubbleSort2(Becon lop[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (lop[j].ms > lop[j + 1].ms) {
                swap(lop[j], lop[j + 1]);
            }
        }
    }
}
void Insertionsort(Becon lop[], int n)
{

    int pos; string x; Becon a;
    for (int i = 1; i < n; i++)
    {
        a = lop[i]; x = lop[i].ms; pos = i - 1;
        while ((pos >= 0) && lop[pos].ms > x)
        {
            lop[pos + 1] = lop[pos];
            pos--;
        }
        lop[pos + 1].ms = x;
        lop[pos + 1] = a;

    }
}
void Shakersort(Becon lop[], int n) {
    int l = 0, r = n - 1, k = n - 1;
    while (l < r) {
        for (int i = r; i > l; i--)
            if (lop[i - 1].ms > lop[i].ms)
            {
                swap(lop[i - 1], lop[i]); k = i;
            }
        l = k;
        for (int j = l; j < r; j++)
            if (lop[j].ms > lop[j + 1].ms)
            {
                swap(lop[j], lop[j + 1]); k = j;
            }
        r = k;
    }
}
void Bosungn(Becon lop[], int& n) {
    int a;
    cout << "\n Nhap so hoc sinh can them vao cuoi danh sach: ";
    cin >> a;
    for (int i = n; i < n + a; i++) {
        cout << "\n Hoc sinh thu " << i + 1;
        NhapHS(lop[i]);
    }
    n = n + a;
    cout << "\n ====== Danh sach cac be sau khi them =======";
    InLop(lop, n);
}
void Bosung1(Becon lop[], int& n) {
    int a;
    do {
        cout << "\n Nhap stt trong danh sach can them hoc sinh (bat dau tu 1): ";
        cin >> a;
        if (a > n) cout << "\n Vi tri xoa khong hop lop le, bat dau tu 1 den " << n;
    } while (a > n || a <= 0);
    for (int i = n; i >= a; i--) {
        lop[i] = lop[i - 1];
    }
    cout << "\nNhap thong tin moi:\n";
    NhapHS(lop[a - 1]);
    n++;
    cout << "\n ====== Danh sach cac be sau khi them =======";
    InLop(lop, n);
}
void Xoa(Becon lop[], int& n) {
    int a;
    do {
        cout << "\n Nhap stt nhan vien can xoa thong tin (bat dau tu 1): ";
        cin >> a;
        if (a > n) cout << "\n Vi tri xoa khong hop lop le, bat dau tu 1 den " << n;
    } while (a > n || a <= 0);
    a--;
    lop[a] = lop[a + 1];
    for (int i = a; i < n - 1; i++) {
        lop[i] = lop[i + 1];
    }
    n--;
    cout << "\n ====== Danh sach cac be sau khi xoa =======";
    InLop(lop, n);
}
void Xoaall(Becon lop[], int& n) {
    n = 0;
    cout << "\n Danh sach da duoc xoa toan bo";
}
void LCBS(Becon lop[], int& n, int& tt, int& sx) {
    int lc;
    do {
        cout << "\n ==== Menu Them Hoc Sinh ====";
        cout << "\n Nhap '1': Them n hoc sinh vao cuoi danh sach";
        cout << "\n Nhap '2': Them 1 hoc sinh vao vi tri bat ky trong danh sach";
        cout << "\n Nhap '3': Ket thuc chinh sua Them, quay lai Menu";
        cout << "\n Nhap lua chon cua ban: ";
        cin >> lc;
        cin.ignore(); tt++; sx = 0;
        switch (lc) {
        case 1: { system("cls");  Bosungn(lop, n); break; }
        case 2: { system("cls");  Bosung1(lop, n); break; }
        case 3: cout << "Quay lai Menu!\n"; break;
        default: cout << "Lua chon khong hop le!\n"; break;
        }
    } while (lc != 3);
}

void LCX(Becon lop[], int& n, int& tt) {
    int lc;
    do {
        cout << "\n ==== Menu Xoa Sinh Vien ====";
        cout << "\n  Nhap '1': Xoa toan bo danh sach";
        cout << "\n  Nhap '2': Xoa 1 hoc sinh o vi tri bat ky trong danh sach";
        cout << "\n  Nhap '3': Ket thuc lua chon Xoa, quay lai Menu";
        cout << "\n  Nhap lua chon cua ban: ";
        cin >> lc;
        cin.ignore(); tt++;
        switch (lc) {
        case 1: Xoaall(lop, n); break;
        case 2: Xoa(lop, n); break;
        case 3: cout << "Quay lai Menu!\n"; break;
        default: cout << "Lua chon khong hop le!\n"; break;
        }
    } while (lc != 3);
}

void LCSX(Becon lop[], int n, int& tt, int& sx) {
    int lc;
    do {
        cout << "\n ==== Menu Sap Xep Sinh Vien ====";
        cout << "\n Nhap '1': Selection sort";
        cout << "\n Nhap '2': Interchangesort";
        cout << "\n Nhap '3': Bubblesort";
        cout << "\n Nhap '4': Insertionsort";
        cout << "\n Nhap '5': Ket thuc sap xep, quay lai Menu";
        cout << "\n Nhap lua chon cua ban: ";
        cin >> lc;
        cin.ignore(); tt++;
        switch (lc) {
        case 1: { system("cls"); Selectionsort(lop, n); sx = 1; cout << "\n Danh sach sau khi sap xep"; InLop(lop, n); break; }
        case 2: { system("cls"); Interchangesort(lop, n); sx = 1; cout << "\n Danh sach sau khi sap xep"; InLop(lop, n); break; }
        case 3: { system("cls"); BubbleSort2(lop, n); sx = 1; cout << "\n Danh sach sau khi sap xep"; InLop(lop, n); break; }
        case 4: { system("cls"); Insertionsort(lop, n); sx = 1; cout << "\n Danh sach sau khi sap xep"; InLop(lop, n); break; }
        case 5: cout << "Quay lai Menu!\n"; break;
        default: cout << "Lua chon khong hop le!\n"; break;
        }
    } while (lc != 5);
}

void DS(Becon lop[], int& n, int& tt, int& sx) {
    int lc;
    do {
        cout << "\n ===========================";
        cout << "\n  Nhap '1': Auto danh sach hs";
        cout << "\n  Nhap '2': Nhap danh sach hs";
        cout << "\n  Nhap '3': [Minimenu] Cac lua chon bo sung danh sach hs";
        cout << "\n  Nhap '4': [Minimenu] Cac lua chon xoa danh sach hs";
        cout << "\n  Nhap '5': [Minimenu] Cac lua chon sap xep danh sach hs";
        cout << "\n  Nhap '6': Ket thuc buoc chinh sua danh sach, den buoc tiep theo";
        cout << "\n  Nhap lua chon cua ban: ";
        cin >> lc;
        cin.ignore(); tt++;
        switch (lc) {
        case 1: Auto(lop, n); break;
        case 2: NhapLop(lop, n); break;
        case 3: LCBS(lop, n, tt, sx); break;
        case 4: LCX(lop, n, tt); break;
        case 5: LCSX(lop, n, tt, sx); break;
        case 6: { system("cls"); cout << "Da hoan tat chinh sua danh sach!\n"; break; }
        default: cout << "Lua chon khong hop le!\n";
        }
    } while (lc != 6);
}
void LCTK(Becon lop[], int n, int& tt, int sx) {
    int lc;
    do {
        cout << "\n ===========================";
        cout << "\n  Nhap '1': Tim kiem tuan tu khong linh canh";
        cout << "\n  Nhap '2': Tim kiem tuan tu co linh canh";
        cout << "\n  Nhap '3': Tim kiem nhi phan (voi danh sach da duoc sap xep)";
        cout << "\n  Nhap '4': Ket thuc tim kiem, quay lai Menu";
        cout << "\n  Nhap lua chon cua ban: ";
        cin >> lc;
        cin.ignore(); tt++;
        switch (lc) {
        case 1: TKTT(lop, n); break;
        case 2: TKTTcolc(lop, n); break;
        case 3: TKNP(lop, n, tt, sx); break;
        case 4: cout << "Quay lai Menu!\n"; break;
        default: cout << "Lua chon khong hop le!\n";
        }
    } while (lc != 4);
}
int main() {
    int t = 0, lc2, tt = 1, sx = 0;
    Becon lop[30];
    DS(lop, t, tt, sx);
    do {
        cout << "\n                ---------MENU---------";
        cout << "\n  Nhap '-1': Quay tro lai thao tac chinh sua danh sach";
        cout << "\n  Nhap '0': In danh sach be tai truong man non Hoa Hong";
        cout << "\n  Nhap '1': Tim kiem thong tin be theo ms";
        cout << "\n  Nhap '2': Thong ke danh sach";
        cout << "\n  Nhap '3': Ket thuc chuong trinh";
        cout << "\n  Nhap lua chon cua ban: ";
        cin >> lc2; cin.ignore(); tt++; system("cls");
        switch (lc2) {
        case -1:DS(lop, t, tt, sx); break;
        case 0: InLop(lop, t); break;
        case 1: LCTK(lop, t, tt, sx); break;
        case 2: Thongke(lop, t); break;
        case 3: { cout << "\n            ---Chuong trinh da duoc ket thuc, so thao tac= " << tt << "---"; break; }
        }
    } while (lc2 != 3);
}

#include <iostream>
#include <string>
using namespace std;

struct SinhVien {
    char hoten[31];
    char masv[6];
    float dtb;
};
void NhapSV(SinhVien& sv) {
    cout << "\n Nhap ho ten: ";
    cin.getline(sv.hoten, 50);
    do {
        cout << "\n Nhap ma hoc sinh: ";
        cin >> sv.masv;
    } while (strlen(sv.masv) != 5);
    cout << "\n Diem trung binh: ";
    cin >> sv.dtb;
}

void Nhap(SinhVien lop[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nNhap sinh vien thu " << i+1 << ": ";
        NhapSV(lop[i]);
        cin.ignore();
    }
}
void XuatSV(SinhVien sv) {
    cout << "\n Ho ten sinh vien: " << sv.hoten;
    cout << "\n Ma sinh vien: " << sv.masv;
    cout << "\n Diem trung binh: " << sv.dtb;
}
void Xuat(SinhVien lop[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\n Sinh vien thu " << i + 1;
        XuatSV(lop[i]);
    }
}
void Tim(SinhVien lop[], int n, char x[]) {
    cout << "\n Nhap ma sinh vien can tim: ";
    cin >> x;
    int t = -1;
    for (int i = 0; i < n; i++) {
        if (strcmp(lop[i].masv, x) == 0) {
            t = i; break;
        }
    }
    if (t != -1) {
        cout << "Tim thay mssv, thong tin sv: "; XuatSV(lop[t]);
    }
    else cout << "Khong tim thay";
}
int main() {
    int t;
    char x[5];
    SinhVien lop[30];
    cout << "Nhap so sv: ";
    cin >> t;
    cin.ignore();
    Nhap(lop, t);
    Xuat(lop, t);
    Tim(lop, t, x);
}

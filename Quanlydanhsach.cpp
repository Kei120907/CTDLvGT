#include <iostream>
#include <string>
using namespace std;

struct SinhVien {
    string hoten;
    string masv;
    float dtb;
};

void NhapSV(SinhVien& sv) {
    do {
        cout << "\n Nhap ma so SV (toi da 10 ky tu): ";
        getline(cin, sv.masv);
    } while (sv.masv.empty() || sv.masv.length() > 10);
    //.empty() tra ve true neu mang rong (len=0)
    do {
        cout << "\n Nhap ho ten SV (toi da 31 ky tu): ";
        getline(cin, sv.hoten);
    } while (sv.hoten.empty() || sv.hoten.length() > 31);

    do {
        cout << "\n Nhap diem trung binh (0-10): ";
        cin >> sv.dtb;
    } while (sv.dtb < 0 || sv.dtb > 10);
    cin.ignore();
}

void NhapLop(SinhVien lop[], int& n) {
    cout << "\n Nhap so sinh vien: ";
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        cout << "\n Sinh vien thu " << i + 1;
        NhapSV(lop[i]);
    }
}

void InSV(SinhVien sv) {
    cout << "\n    Ma so SV: " << sv.masv;
    cout << "\n    Ho ten: " << sv.hoten;
    cout << "\n    Diem trung binh: " << sv.dtb;
}

void InLop(SinhVien lop[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\n Sinh vien thu " << i + 1;
        InSV(lop[i]);
    }
}

void TKTT(SinhVien lop[], int n) {
    string x;
    cout << "\nNhap ma so can tim: ";
    getline(cin, x);
    int t = -1;
    for (int i = 0; i < n; i++) {
        if (x == lop[i].masv) {
            t = i; break;
        }
    }
    if (t != -1) {
        cout << "Tim thay ma so, thong tin SV: ";
        InSV(lop[t]);
    }
    else cout << "Khong tim thay";
}


void TKTTcolc(SinhVien lop[], int n) {
    string x;
    cout << "\nNhap ma so can tim: ";
    getline(cin, x);
    int t = 0;
    lop[n].masv = x;
    while (lop[t].masv != x) {
        t++;
    }
    if (t < n) {
        cout << "Tim thay ma so, thong tin SV: ";
        InSV(lop[t]);
    }
    else cout << "Khong tim thay";
}

void TKNP(SinhVien lop[], int n) {
    int l = 0, r = n - 1;
    int m = (l + r) / 2;
    string x;
    do {
        cout << "\n Nhap ma SV can tim (toi da 10 ky tu): ";
        getline(cin, x);
    } while (x.empty() || x.length() > 10);

    while (l <= r && lop[m].masv != x) {
        if (lop[m].masv > x) {
            r = m - 1;
        }
        else {
            l = m + 1;
        }
        m = (l + r) / 2;
    }
    if (l > r) cout << "Khong tim thay";
    else {
        cout << "Tim thay ma so, thong tin: ";
        InSV(lop[m]);
    }
}

void DTBmax(SinhVien lop[], int n) {
    int vt = 0;
    for (int i = 1; i < n; i++) {
        if (lop[i].dtb > lop[vt].dtb) {
            vt = i;
        }
    }
    cout << "\n Sinh vien co DTB cao nhat: ";
    InSV(lop[vt]);
}

void Auto(SinhVien lop[], int& n) {
    n = 5;
    lop[0] = { "Nguyen Van A","SV001",8.5 };
    lop[1] = { "Tran Thi B","SV002",7.2 };
    lop[2] = { "Le Van C","SV003",9.0 };
    lop[3] = { "Pham Thi D","SV004",6.8 };
    lop[4] = { "Hoang Van E","SV005",7.9 };
    InLop(lop, n);
}


void Bosungn(SinhVien lop[], int& n) {
    int a;
    cout << "\n Nhap so sinh vien can them vao cuoi danh sach: ";
    cin >> a;
    for (int i = n; i < n + a; i++) {
        cout << "\n Sinh vien thu " << i + 1;
        NhapSV(lop[i]);
    }
    n = n + a;
    cout << "\n ======Danh sach sinh vien sau khi them=======";
    InLop(lop, n);
}
void Bosung1(SinhVien lop[], int& n) {
    int a;
    do {
        cout << "\n Nhap stt trong danh sach can them sinh vien (bat dau tu 1): ";
        cin >> a;
        if (a > n) cout << "\n Vi tri xoa khong hop lop le, bat dau tu 1 den " << n;
    } while (a > n || a <= 0);
    for (int i = n; i >= a; i--) {
        lop[i] = lop[i - 1];
    }
    cout << "\nNhap thong tin SV moi:\n";
    NhapSV(lop[a - 1]);
    n++;
    cout << "\n ======Danh sach sinh vien sau khi them=======";
    InLop(lop, n);
}
void Xoa(SinhVien lop[], int& n) {
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
    cout << "\n ======Danh sach sinh vien sau khi xoa=======";
    InLop(lop, n);
}
void Xoaall(SinhVien lop[], int& n) {
    n = 0;
    cout << "\n Danh sach da duoc xoa toan bo";
}
void LCBS(SinhVien lop[], int& n, int& tt) {
    int lc;
    do {
        cout << "\n ==== Menu Them Sinh Vien ====";
        cout << "\n Nhap '1': Them n sinh vien vao cuoi danh sach";
        cout << "\n Nhap '2': Them 1 sinh vien vao vi tri bat ky trong danh sach";
        cout << "\n Nhap '3': Ket thuc tim kiem, quay lai Menu";
        cout << "\n Nhap lua chon cua ban: ";
        cin >> lc;
        cin.ignore(); tt++;
        switch (lc) {
        case 1: Bosungn(lop, n); break;
        case 2: Bosung1(lop, n); break;
        case 3: cout << "Quay lai Menu!\n"; break;
        default: cout << "Lua chon khong hop le!\n"; break;
        }
    } while (lc != 3);
}

void LCX(SinhVien lop[], int& n, int& tt) {
    int lc;
    do {
        cout << "\n ==== Menu Xoa Sinh Vien ====";
        cout << "\n Nhap '1': Xoa toan bo danh sach";
        cout << "\n Nhap '2': Xoa 1 sinh vien o vi tri bat ky trong danh sach";
        cout << "\n Nhap '3': Ket thuc tim kiem, quay lai Menu";
        cout << "\n Nhap lua chon cua ban: ";
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


void DS(SinhVien lop[], int& n, int& tt) {
    int lc;
    do {
        cout << "\n ===========================";
        cout << "\n Nhap '1': Auto danh sach SV";
        cout << "\n Nhap '2': Nhap danh sach SV";
        cout << "\n Nhap '3': Ngan lua chon bo sung sinh vien vao danh sach";
        cout << "\n Nhap '4': Ngan lua chon xoa sinh vien khoi danh sach";
        cout << "\n Nhap '5': Ket thuc buoc chinh sua danh sach";
        cout << "\n Nhap lua chon cua ban: ";
        cin >> lc;
        cin.ignore(); tt++;
        switch (lc) {
        case 1: Auto(lop, n); break;
        case 2: NhapLop(lop, n); break;
        case 3: LCBS(lop, n, tt); break;
        case 4: LCX(lop, n, tt); break;
        case 5: cout << "Da hoan tat chinh sua danh sach!\n"; break;
        default: cout << "Lua chon khong hop le!\n"; break;
        }
    } while (lc != 5);
}
void LCTK(SinhVien lop[], int n, int& tt) {
    int lc;
    do {
        cout << "\n ===========================";
        cout << "\n Nhap '1': Tim kiem tuan tu khong linh canh";
        cout << "\n Nhap '2': Tim kiem tuan tu co linh canh";
        cout << "\n Nhap '3': Tim kiem nhi phan (voi danh sach da sap xep)";
        cout << "\n Nhap '4': Ket thuc tim kiem, quay lai Menu";
        cout << "\n Nhap lua chon cua ban: ";
        cin >> lc;
        cin.ignore(); tt++;
        switch (lc) {
        case 1: TKTT(lop, n); break;
        case 2: TKTTcolc(lop, n); break;
        case 3: TKNP(lop, n); break;
        case 4: cout << "Quay lai Menu!\n"; break;
        default: cout << "Lua chon khong hop le!\n"; break;
        }
    } while (lc != 4);
}

int main() {
    int t, lc2, tt = 1;
    SinhVien lop[30];
    DS(lop, t, tt);
    do {
        cout << "\n ---------MENU---------";
        cout << "\n Nhap '-1': Quay lai thao tac chinh sua danh sach";
        cout << "\n Nhap '0': In danh sach SV";
        cout << "\n Nhap '1': [Mini menu] Tim kiem thong tin SV theo ma so";
        cout << "\n Nhap '2': Tim SV co DTB cao nhat";
        cout << "\n Nhap '3': Ket thuc chuong trinh";
        cout << "\n Nhap lua chon cua ban: ";
        cin >> lc2; cin.ignore(); tt++;
        switch (lc2) {
        case -1: DS(lop, t, tt); break;
        case 0: InLop(lop, t); break;
        case 1: LCTK(lop, t, tt); break;
        case 2: DTBmax(lop, t); break;
        case 3: cout << "\n ---Chuong trinh ket thuc, so thao tac= " << tt << "---"; break;
        default: cout << "Lua chon khong hop le!\n"; break;
        }
    } while (lc2 != 3);
}

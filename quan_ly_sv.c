#include <stdio.h>
#include <string.h>

#define MAX_SV 100

// 7 mảng song song
char ho_lot[MAX_SV][40];
char ten[MAX_SV][20];
char ngaysinh[MAX_SV][15];
char gioitinh[MAX_SV][5];
char diachi[MAX_SV][80];
char masv[MAX_SV][20];

int soSV = 0;
int daSapXep = 0;
int daCapMa  = 0;

void xoaNewline(char *s) {
    int len = strlen(s);
    if (len > 0 && s[len-1] == '\n')
        s[len-1] = '\0';
}

// Ham nhap thong tin 1 sinh vien tu ban phim
void nhapMotSV() {
    char buf[5];
 
    printf("  Ho va chu lot          : ");
    fgets(ho_lot[soSV], 40, stdin);
    xoaNewline(ho_lot[soSV]);
 
    printf("  Ten                    : ");
    fgets(ten[soSV], 20, stdin);
    xoaNewline(ten[soSV]);
 
    printf("  Ngay sinh (DD/MM/YYYY) : ");
    fgets(ngaysinh[soSV], 15, stdin);
    xoaNewline(ngaysinh[soSV]);
 
    printf("  Gioi tinh (0=Nu/1=Nam) : ");
    fgets(buf, 5, stdin);
    if (buf[0] == '1') strcpy(gioitinh[soSV], "Nam");
    else               strcpy(gioitinh[soSV], "Nu");
 
    printf("  Dia chi                : ");
    fgets(diachi[soSV], 80, stdin);
    xoaNewline(diachi[soSV]);
 
    strcpy(masv [soSV], "chua cap");
 
    soSV++;
}
 
//Them nhieu sinh vien tu ban phim 
void themTuBanPhim() {
    int n, i;
 
    printf("Nhap so luong sinh vien can them: ");
    scanf("%d", &n);
    getchar();
 
    if (soSV + n > MAX_SV) {
        printf(">> Chi co the them toi da %d sinh vien nua!\n", MAX_SV - soSV);
        n = MAX_SV - soSV;
    }
 
    for (i = 0; i < n; i++) {
        printf("\n--- Sinh vien %d ---\n", soSV + 1);
        nhapMotSV();
    }
 
    printf(">> Them thanh cong %d sinh vien!\n", n);
}

void themTuFile() {
    char tenfile[50];
    FILE *f;
    char dong[200];
    char *token;
    int dem = 0;
 
    printf("Nhap ten file (vi du: danhsach.txt): ");
    fgets(tenfile, 50, stdin);
    xoaNewline(tenfile);
 
    f = fopen(tenfile, "r");
    if (!f) {
        printf(">> Loi: Khong mo duoc file '%s'!\n", tenfile);
        return;
    }
 
    while (fgets(dong, 200, f) && soSV < MAX_SV) {
        xoaNewline(dong);
        if (strlen(dong) < 3) continue;
 
        token = strtok(dong, ",");
        if (!token) continue;
        strcpy(ho_lot[soSV], token);
 
        token = strtok(NULL, ",");
        if (!token) continue;
        strcpy(ten[soSV], token);
 
        token = strtok(NULL, ",");
        if (!token) continue;
        strcpy(ngaysinh[soSV], token);
 
        token = strtok(NULL, ",");
        if (!token) continue;
        strcpy(gioitinh[soSV], token);
 
        token = strtok(NULL, ",");
        if (!token) continue;
        strcpy(diachi[soSV], token);
 
        strcpy(masv [soSV], "chua cap");
 
        soSV++;
        dem++;
    }
 
    fclose(f);
    printf(">> Doc thanh cong %d sinh vien tu file '%s'!\n", dem, tenfile);
}
 
void themSinhVien() {
    int lua;
 
    printf("\n=== THEM SINH VIEN ===\n");
 
    if (soSV >= MAX_SV) {
        printf(">> Lop da day %d sinh vien!\n", MAX_SV);
        return;
    }
 
    printf("  1. Nhap du lieu tu ban phim\n");
    printf("  2. Nhap du lieu tu file (.txt)\n");
    printf("Chon: ");
    scanf("%d", &lua);
    getchar();
 
    if (lua == 1) themTuBanPhim();
    else          themTuFile();
 
    daSapXep = 0;
    daCapMa  = 0;
 
    printf(">> Lop hien co %d sinh vien.\n", soSV);
}
 
int main() {
    themSinhVien();  // test thu chuc nang them

    // In ra kiem tra
    int i;
    for (i = 0; i < soSV; i++) {
        printf("%s %s - %s - %s - %s\n",
               ho_lot[i], ten[i], ngaysinh[i], gioitinh[i], diachi[i]);
    }

    return 0;
}


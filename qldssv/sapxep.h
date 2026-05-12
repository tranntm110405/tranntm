#ifndef SAPXEP_H
#define SAPXEP_H

/* Doi cho toan bo thong tin cua 2 sinh vien */
void hoiDoi(int i, int j) {
    char tmp[100];

    strcpy(tmp, ho_lot[i]);   strcpy(ho_lot[i],   ho_lot[j]);   strcpy(ho_lot[j],   tmp);
    strcpy(tmp, ten[i]);      strcpy(ten[i],       ten[j]);      strcpy(ten[j],      tmp);
    strcpy(tmp, ngaysinh[i]); strcpy(ngaysinh[i],  ngaysinh[j]); strcpy(ngaysinh[j], tmp);
    strcpy(tmp, gioitinh[i]); strcpy(gioitinh[i],  gioitinh[j]); strcpy(gioitinh[j], tmp);
    strcpy(tmp, diachi[i]);   strcpy(diachi[i],    diachi[j]);   strcpy(diachi[j],   tmp);
    strcpy(tmp, masv[i]);     strcpy(masv[i],      masv[j]);     strcpy(masv[j],     tmp);
    strcpy(tmp, email[i]);    strcpy(email[i],     email[j]);    strcpy(email[j],    tmp);
}

/* Bubble Sort theo Ten, neu bang thi so sanh Ho lot */
void sapXepDanhSach() {
    int i, j, doicho;

    printf("\n=== SAP XEP THEO ALPHABE (Ten, Ho lot) ===\n");

    if (soSV == 0) {
        printf(">> Danh sach trong!\n");
        return;
    }

    for (i = 0; i < soSV - 1; i++) {
        for (j = 0; j < soSV - i - 1; j++) {
            doicho = strcmp(ten[j], ten[j+1]);
            if (doicho == 0)
                doicho = strcmp(ho_lot[j], ho_lot[j+1]);
            if (doicho > 0)
                hoiDoi(j, j+1);
        }
    }

    daSapXep = 1;
    daCapMa  = 0;
    printf(">> Sap xep thanh cong!\n");

    inDanhSach();
}

#endif

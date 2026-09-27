#include <stdio.h>

int main(void) {
    int N;
    long long tong_doanh_thu = 0;

    printf("Nhap so luong giao dich: ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("Loi: So luong giao dich phai lon hon 0!\n");
        return 0;
    }

    for (int i = 1; i <= N; i++) {
        int ma_mon;
        int size;
        int so_topping;
        int member;

        long long gia_co_ban;
        long long tong_tien;

        printf("\n--- Giao dich %d ---\n", i);

        printf("Nhap ma mon (-1: NGAT | 0: HUY | 1-3: MON): ");
        scanf("%d", &ma_mon);

        // Ma -1: ngat khan cap toan bo ca
        if (ma_mon == -1) {
            printf("TIN HIEU NGAT KHAN CAP! Dung ca lam viec.\n");
            break;
        }

        // Ma 0: huy don, bo qua giao dich
        if (ma_mon == 0) {
            printf("Giao dich da bi huy.\n");
            continue;
        }

        // Kiem tra ma mon
        if (ma_mon != 1 && ma_mon != 2 && ma_mon != 3) {
            printf("Loi: Ma mon khong hop le!\n");
            continue;
        }

        printf("Nhap size (1-S | 2-M | 3-L): ");
        scanf("%d", &size);

        printf("Nhap so topping (0-5): ");
        scanf("%d", &so_topping);

        printf("Nhap member (1-Gold | 0-Thuong): ");
        scanf("%d", &member);

        // Kiem tra size
        if (size != 1 && size != 2 && size != 3) {
            printf("Loi: Size khong hop le!\n");
            continue;
        }

        // Kiem tra so topping
        if (so_topping < 0 || so_topping > 5) {
            printf("Loi: So topping phai tu 0 den 5!\n");
            continue;
        }

        // Xac dinh gia co ban
        if (ma_mon == 1) {
            gia_co_ban = 29000;
        } else if (ma_mon == 2) {
            gia_co_ban = 39000;
        } else {
            gia_co_ban = 49000;
        }

        // Cong phu thu size
        if (size == 2) {
            gia_co_ban += 6000;
        } else if (size == 3) {
            gia_co_ban += 10000;
        }

        // Tinh tong tien
        tong_tien = gia_co_ban + so_topping * 8000;

        // Gold giam 10%
        if (member == 1) {
            tong_tien = tong_tien * 90 / 100;
        }

        printf("Tong tien giao dich: %lld VND\n", tong_tien);

        // Cong vao doanh thu
        tong_doanh_thu += tong_tien;
    }

    printf("\n===== KET QUA CHOT CA =====\n");
    printf("Tong doanh thu: %lld VND\n", tong_doanh_thu);

    return 0;
}
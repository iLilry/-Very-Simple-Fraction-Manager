#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
struct PHANSO
{
    int tu;
    int mau;
};


void input(PHANSO &ps)
{
    printf("Nhap tu so: ");
    while (scanf("%d",&ps.tu) != 1)
    {
        printf("BAN PHAI NHAP SO cutie a :3");
        while(getchar() != '\n');
        printf("\nNhap lai tu so: ");
    }


    do{
    printf("Nhap mau so (khac 0): ");
    if (scanf("%d",&ps.mau) != 1)
    {
        printf("BAN PHAI NHAP SO cutie a :3");
        while(getchar() != '\n');
            ps.mau = 0;
    }
    if(ps.mau==0)   printf("Nhap lai mau so khac 0\n");
    }while(ps.mau==0);
}

void output(PHANSO ps)
{
    printf("%d/%d\n",ps.tu,ps.mau);
}



void menu()
{   printf("MENU:");
    printf("\n1. Nhap phan so");
    printf("\n2. Xuat phan so");
    printf("\n3. Rut gon phan so");
    printf("\n4. Tong 2 phan so");
    printf("\n5. Hieu 2 phan so");
    printf("\n6. Tich 2 phan so");
    printf("\n7. Thuong 2 phan so");
    printf("\n8. Nhap mang phan so");

}

int ucln(int a, int b)
{
    while(b!=0)
        {int r = a%b;
        a = b;
        b = r;
        }
return a;
}

void rutgonphanso(PHANSO &ps)
    {
        int rg = abs(ucln(ps.tu,ps.mau));
        if(rg > 1)
            {
                ps.tu /= rg;
                ps.mau /= rg;
            } 

    }
PHANSO tongphanso(PHANSO ps1, PHANSO ps2)
{   PHANSO ps;
    ps.tu = ps1.tu*ps2.mau+ps2.tu*ps1.mau;
    ps.mau = ps1.mau*ps2.mau;
    rutgonphanso(ps);
    return ps;
}

PHANSO hieuphanso(PHANSO ps1, PHANSO ps2)
{   PHANSO ps;
    ps.tu = ps1.tu*ps2.mau-ps2.tu*ps1.mau;
    ps.mau = ps1.mau*ps2.mau;
    rutgonphanso(ps);
    return ps;
}

PHANSO tichphanso(PHANSO ps1, PHANSO ps2)
{
    PHANSO ps;
    ps.tu = ps1.tu*ps2.tu;
    ps.mau = ps1.mau*ps2.mau;
    rutgonphanso(ps);
    return ps;
}

PHANSO thuongphanso(PHANSO ps1, PHANSO ps2)
{
    PHANSO ps;
    ps.tu = ps1.tu*ps2.mau;
    ps.mau = ps1.mau*ps2.tu;
    rutgonphanso(ps);
    return ps;
}
void nhapmang(PHANSO p[],int &n)
    {
        printf("Nhap so luong phan so: ");
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
            {
                printf("Nhap phan so thu [%d]: \n",i+1);
                input(p[i]);
            }
    }   

    void xuatmang(PHANSO p[],int n)
    {
        for(int i = 0; i < n; i++)
        {
            printf("Phan so thu [%d] la: ",i+1);
            output(p[i]);
        }
    }

int main()

{   
    int chon;
    int n;

    PHANSO ps,ps1,ps2,p[MAX];
    menu();
    do{
        printf("\nChon chuc nang, chon 0 de thoat :");
        if(scanf("%d",&chon) !=1 )
        {
            printf("BAN PHAI NHAP SO cutie a :3");
        while(getchar() != '\n');
            chon = -1;
        continue;
        }
    
        switch(chon)
        {
            case 1 : input(ps);
                     menu(); break;
            case 2 : printf("Phan so vua nhap la: ");
                     output(ps);
                     menu(); break;
            case 3 : rutgonphanso(ps);
                     printf("Phan so sau khi rut gon: "); output(ps);
                     menu(); break;
            case 4 : printf("Nhap phan so thu 1: "); input(ps1);
                     printf("\nNhap phan so thu 2: ");input(ps2);
                     printf("\nTong cua 2 phan so la: ");
                     ps = tongphanso(ps1,ps2);
                     output(ps);
                     menu(); break;
            case 5 : printf("Nhap phan so thu 1: "); input(ps1);
                     printf("\nNhap phan so thu 2: "); input(ps2);
                     printf("\nHieu cua 2 phan so la:  ");
                     ps = hieuphanso(ps1,ps2);
                     output(ps);
                     menu(); break;
            case 6:  printf("Nhap phan so thu 1: "); input(ps1);
                     printf("\nNhap phan so thu 2: "); input(ps2);
                     printf("\nTich cua 2 phan so la:  ");
                     ps = tichphanso(ps1,ps2);
                     output(ps);
                     menu(); break;
            case 7:  printf("Nhap phan so thu 1: "); input(ps1);
                     printf("\nNhap phan so thu 2: "); input(ps2);
                     printf("\nThuong cua 2 phan so la:  ");
                     ps = thuongphanso(ps1,ps2);
                     output(ps);
                     menu(); break;
            case 8:  nhapmang(p,n);
                     xuatmang(p,n);
                     menu();
                     break;
            case 0: printf("ok!"); break;
            default: printf("Error~There no such option."); 

        }
    }while(chon!=0);
}

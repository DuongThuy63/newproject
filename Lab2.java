/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab2;

/**
 *
 * @author NuNo39
 */
import java.util.Scanner;
public class Lab2 {

    /**
     * @param args the command line arguments
     */
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] sach = new String[6];
        int[] nam = new int[6];
        nhapThongTinSach(sc, sach, nam);
        inThongTinSach( sach, nam);
    }

    private static void nhapThongTinSach(Scanner sc, String[] sach, int[] nam) {
        for (int i = 1; i <6; i++) {
            System.out.print("Nhap ten sach thu " + i + ": ");
            sach[i] = sc.nextLine();
            boolean hople = false;
            while (!hople) {
                System.out.print("Nam xuat ban(2000 -> 2023): ");
                nam[i] = sc.nextInt();
                sc.nextLine();
                hople = checkNam(nam[i]);
                if (!hople) {
                    System.out.println("Khong hop le! Vui long nhap lai.");
                }
            }
        }
        
    }

    private static boolean checkNam(int nam) {
        return nam > 2000 && nam < 2023;
    }

    private static void inThongTinSach( String[] sach, int[] nam) {
        for (int i = 1; i <6; i++) {
            System.out.println("Thong tin sach:");
            System.out.println("Ten sach: " + sach[i]);
            System.out.println("Nam xuat ban: " + nam[i]);
            int khuyenmai = tinhKM(nam[i]);
            System.out.println("Khuyen mai: " + khuyenmai + "%");
             System.out.println("__d______________________");
        }
    }

    private static int tinhKM(int nam) {
        if (nam < 2005) {
            return 80;
        } else if (nam < 2015) {
            return 50;
        } else if (nam < 2020) {
            return 30;
        } else {
            return 10;
        }
    }

    private static int CheckSoNguyen(int n) {
        int a = 1;
        if (Math.ceil(n) != Math.floor(n))
            a = 0;
        return a;
    }
}